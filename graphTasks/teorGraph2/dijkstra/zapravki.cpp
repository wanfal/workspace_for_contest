#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

struct Node
{
    int index;
    std::vector<std::pair<int, Node*>> neighs;

    Node(int _index){
        index = _index;
    }

    void addChild(Node* child, int ves){
        neighs.push_back({ves, child});
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::unordered_map<int, Node*> graph;
    int numNodes, numEdges, city1, city2, end, start=1;
    std::cin >> numNodes;
    end = numNodes;
    for(int i=0;i<numNodes;i++){
        graph[i+1] = new Node(i+1);
    }

    std::vector<int> benzCost(numNodes);
    for(int i=0;i<numNodes;i++){
        std::cin >> benzCost[i];
    }

    std::cin >> numEdges;
    for(int i=0;i<numEdges;i++){
        std::cin >> city1 >> city2;
        graph[city1]->addChild(graph[city2], benzCost[city1-1]);
        graph[city2]->addChild(graph[city1], benzCost[city2-1]);
    }
    long long inf = LLONG_MAX/2;
    std::set<std::pair<long long, int>> nodesToPass;
    std::vector<long long> dists(numNodes+1, inf);
    dists[start]=0;
    nodesToPass.insert({0, start});

    while(!nodesToPass.empty()){
        auto [currDist, currIndex] = *nodesToPass.begin();
        nodesToPass.erase(nodesToPass.begin());

        for(const auto& [ves,child]:graph[currIndex]->neighs){
            if(currDist+ves < dists[child->index]){
                if(dists[child->index] != inf){
                    nodesToPass.erase({dists[child->index], child->index});
                }
                dists[child->index] = currDist+ves;
                nodesToPass.insert({dists[child->index], child->index});
            }
        }
    }

    if(dists[end]!=inf){
        std::cout << dists[end] << '\n';
    }
    else{
        std::cout << -1 << '\n';
    }

    return 0;
}
