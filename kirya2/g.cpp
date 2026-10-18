#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>

struct Node
{
    int index;
    int value;
    Node* parent=nullptr;
    std::vector<std::pair<int, Node*>> nodes;
    Node(int _index, int _value){
        index = _index;
        value=_value;
        nodes = std::vector<std::pair<int, Node*>>();
    }

    void addChild(Node* node, int ves){
        nodes.push_back(std::make_pair(ves, node));
    }
};

int main()
{
    int numNodes, numRebra, cityType;
    std::cin >> numNodes >> numRebra;
    std::unordered_map<int, Node*> graph;
    graph[0] = new Node(0, 0);
    for(int i=1;i<numNodes+1;i++){
        std::cin >> cityType;
        graph[i] = new Node(i, cityType);
        if(cityType==1){
            graph[0]->addChild(graph[i], 0);
        }
    }
    int city1, city2, ves;
    for(int i=0;i<numRebra;i++){
        std::cin >> city1 >> city2 >> ves;
        auto it1 = graph.find(city1);
        auto it2 = graph.find(city2);
        it1->second->addChild(it2->second, ves);
        it2->second->addChild(it1->second, ves);
    
    }

    long long mnogo = LLONG_MAX;
    std::vector<long long> dist(numNodes+1, mnogo);
    dist[0] = 0;
    std::set<std::pair<long long, int>> minDistNodes;
    minDistNodes.insert({0, 0});

    while(!minDistNodes.empty()){
        auto [d, index] = *minDistNodes.begin();
        minDistNodes.erase(minDistNodes.begin());
        if(d!=dist[index]){
            continue;
        }

        for(const auto& [ves, child]:graph[index]->nodes){
            if(d+ves < dist[child->index]){
                if(dist[child->index]!=mnogo){
                    minDistNodes.erase({dist[child->index], child->index});
                }
                dist[child->index] = d+ves;
                child->parent = graph[index];
                minDistNodes.insert({dist[child->index], child->index});
            }
        }
    }

    Node* best = nullptr;
    long long bestDist = mnogo;
    for(int i=1;i<=numNodes;i++){
        if(graph[i]->value==2 && dist[i]<bestDist){
            bestDist=dist[i];
            best=graph[i];
        }
    }

    if(!best){
        std::cout << -1 << '\n';
        return 0;
    }
    Node* end = best;
    Node* curr = end;
    while(curr->parent!=graph[0]){
        curr = curr->parent;
    }
    std::cout << curr->index << ' ' << end->index << ' ' << bestDist << '\n';
    return 0;
}
