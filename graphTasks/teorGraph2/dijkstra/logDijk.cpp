#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_map>

struct Node
{
    int index;
    std::vector<std::pair<int, Node*>> neighs;

    Node(int _index){
        index = _index;
    }

    void addChild(Node* node, int ves){
        neighs.push_back(std::make_pair(ves, node));
    }
};


int main()
{
    int numNodes, numEgdes, start;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> numNodes >> numEgdes >> start;
    std::unordered_map<int, Node*> graph;
    for(int i=0;i<numNodes;i++){
        graph[i] = new Node(i);
    }
    int node1, node2, ves;
    for(int i=0;i<numEgdes;i++){
        std::cin >> node1 >> node2 >> ves;
        graph[node1]->addChild(graph[node2], ves);
        graph[node2]->addChild(graph[node1], ves);
    }

    long long inf = LLONG_MAX/2;
    std::set<std::pair<long long, int>> nodesToPass;
    std::vector<long long> dists(numNodes, inf);
    dists[start] = 0;
    nodesToPass.insert({0, start});

    while(!nodesToPass.empty()){
        auto [currDist, currIndex] = *nodesToPass.begin();
        nodesToPass.erase(nodesToPass.begin());
        for(const auto& [ves, child]:graph[currIndex]->neighs){
            if(ves+currDist < dists[child->index]){
                if(dists[child->index]!=inf){
                    nodesToPass.erase({dists[child->index], child->index});
                }
                dists[child->index] = ves+currDist;
                nodesToPass.insert({dists[child->index], child->index});
            }
        }
    }
    for(int i=0;i<numNodes;i++){
        if(dists[i]==inf){
            std::cout << 2009000999 << ' ';
        }
        else{
            std::cout << dists[i] << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
