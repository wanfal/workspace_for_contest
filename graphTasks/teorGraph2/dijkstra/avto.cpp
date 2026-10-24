#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <set>

struct Edge
{
    int to;
    int depart;
    int arrive;
};

struct Node
{
    int index;
    std::vector<Edge> neighs;

    Node(int _index){
        index = _index;
    }

    void addChild(int _dep, int _arr, Node* node){
        neighs.push_back({node->index, _dep, _arr});
    }
};


int main()
{
    std::unordered_map<int, Node*> graph;
    int numNodes, numEdges, start, end, deprt, node1, node2, ves;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> numNodes;

    for(int i=1;i<=numNodes;i++){
        graph[i] = new Node(i);
    }

    std::cin >> start >> end;
    std::cin >> numEdges;
    for(int i=0;i<numEdges;i++){
        std::cin >> node1 >> deprt >> node2 >> ves;
        graph[node1]->addChild(deprt, ves, graph[node2]);
    }

    long long inf = LLONG_MAX/2;
    std::vector<long long> dists(numNodes+1, inf);
    dists[start] = 0;
    std::set<std::pair<long long, int>> nodesToPass;
    nodesToPass.insert({0, start});

    while(!nodesToPass.empty()){
        auto [currTime, currIndex] = *nodesToPass.begin();
        nodesToPass.erase(nodesToPass.begin());

        if(currTime > dists[currIndex]) continue;

        for(const auto& e : graph[currIndex]->neighs){
            if(e.depart < currTime) continue;
            if(e.arrive < dists[e.to]){
                if(dists[e.to] != inf){
                    nodesToPass.erase({dists[e.to], e.to});
                }
                dists[e.to] = e.arrive;
                nodesToPass.insert({dists[e.to], e.to});
            }
        }
    }

    if(dists[end] == inf) std::cout << -1 << '\n';
    else std::cout << dists[end] << '\n';

    return 0;
}