#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>

struct Node
{
    int index;
    std::vector<std::pair<double, Node*>> neighs;

    Node(int _index){
        index= _index;
    }

    void addChild(Node* child, double ves){
        neighs.push_back({ves, child});
    }
};


double getBestW(double ves){
    double curr = ves, cost=0;
    while(true){
        if(curr/2+1>=curr){
            return curr+cost;
        }
        curr = curr/2;
        cost++;
    }
    return 0;
}

int main()
{
    int nt;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> nt;
    for(int t=0;t<nt;t++){
        int numNodes, numEgdes;
        std::cin >> numNodes >> numEgdes;
        std::unordered_map<int, Node*> graph;
        for(int i=1;i<=numNodes;i++){
            graph[i] = new Node(i);
        }
        int node1, node2, ves;
        for(int i=0;i<numEgdes;i++){
            std::cin >> node1 >> node2 >> ves;
            graph[node1]->addChild(graph[node2], getBestW(ves));
        }

        double inf = 100000000.0;
        std::vector<double> dists(numNodes+1, inf);
        std::set<std::pair<double, int>> nodesToPass;
        nodesToPass.insert({0, 1});
        dists[1] = 0;

        while(!nodesToPass.empty()){
            auto [currDist, currIndex] = *nodesToPass.begin();
            nodesToPass.erase(nodesToPass.begin());

            for(const auto& [d, child]:graph[currIndex]->neighs){
                if(currDist+d<dists[child->index]){
                    if(dists[child->index]!=inf){
                        nodesToPass.erase({dists[child->index], child->index});
                    }
                    dists[child->index] = currDist+d;
                    nodesToPass.insert({dists[child->index], child->index});
                }
            }
        }

        if(dists[numNodes]==inf){
            std::cout << -1 << '\n';
        }
        else{
            std::cout << (long long)std::ceil(dists[numNodes]) << '\n';
        }
    }
    return 0;
}
