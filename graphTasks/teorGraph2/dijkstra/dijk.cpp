#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

struct Node
{
    int index;
    Node* parent=nullptr;
    std::vector<std::pair<int, Node*>> nodes;
    Node(int _index){
        index = _index;
    }

    void addChild(Node* node, int ves){
        nodes.push_back(std::make_pair(ves, node));
    }
};

int main(){
    int mtxSize, start, end;
    std::cin >> mtxSize >> start >> end;
    std::unordered_map<int, Node*> graph;

    for(int i=1;i<=mtxSize;i++){
        graph[i] = new Node(i);
    }
    int ves;
    for(int i=1;i<mtxSize+1;i++){
        for(int j=1;j<mtxSize+1;j++){
            std::cin >> ves;
            if(i==j || ves==-1){
                continue;
            }
            graph[i]->addChild(graph[j], ves);
        }
    }
    long long inf = LLONG_MAX/2;
    std::vector<long long> dist(mtxSize+1, inf);
    std::set<std::pair<long long, int>> nodesToPass;
    nodesToPass.insert({0, start});
    dist[start] = 0;
    long long currDist;
    int currIndex;
    while(!nodesToPass.empty()){
        currDist = (*nodesToPass.begin()).first;
        currIndex = (*nodesToPass.begin()).second;
        nodesToPass.erase(nodesToPass.begin());

        for(const auto& [ves, child]:graph[currIndex]->nodes){
            if(currDist+ves < dist[child->index]){
                if(dist[child->index]!=inf){
                    nodesToPass.erase({dist[child->index], child->index});
                }
                dist[child->index] = currDist+ves;
                nodesToPass.insert({dist[child->index], child->index});
                child->parent = graph[currIndex];
            }
        }
    }

    std::vector<int> path;
    if(dist[end]!=inf){
        Node* curr = graph[end];
        while(curr!=nullptr){
            path.push_back(curr->index);
            if(curr->index==start){
                break;
            }
            curr = curr->parent;
        }
        for(int i=path.size()-1;i>=0;i--){
            std::cout << path[i] << ' ';
        }
        std::cout << '\n';
    }
    else{
        std::cout << -1 << '\n';
    }
    return 0;
}