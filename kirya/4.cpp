#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Node
{
    int index;
    std::vector<Node*> nodes;
    Node(int _index){
        index = _index;
        nodes = std::vector<Node*>();
        nodes = std::vector<Node*>();
    }

    void addChild(Node* node){
        nodes.push_back(node);
    }

    void removeChild(int _index){
        auto iter = nodes.begin();
        for(int i=0;i<nodes.size();i++){
            if((*iter)->index==_index){
                nodes.erase(iter);
                return;
            }
        }
    }
};

void adjToGraph(const std::vector<std::vector<int>>& edges, std::unordered_map<int, Node*>& graph){
    for(const auto& e:edges){
        int u = e[0], v = e[1];
        if (u == v) continue;
        auto itU = graph.find(u - 1);
        auto itV = graph.find(v - 1);
        if (itU == graph.end() || itV == graph.end()) continue;
        itU->second->addChild(itV->second);
        itV->second->addChild(itU->second);
    }
}

void removeRebro(const std::vector<std::vector<int>>& edges, std::unordered_map<int, Node*>& graph, int numToRemove){
    const std::vector<int>& reb = edges[numToRemove-1];
    int u = reb[0];
    int v = reb[1];
    if (u == v) return;

    auto itU = graph.find(u-1);
    auto itV = graph.find(v - 1);
    if (itU==graph.end() || itV==graph.end()) return;

    auto& uNodes = itU->second->nodes;
    for(auto it=uNodes.begin();it!=uNodes.end();it++){
        if((*it)->index == v){
            uNodes.erase(it);
            break;
        }
    }

    auto& vNodes = itV->second->nodes;
    for(auto it=vNodes.begin();it!=vNodes.end();it++){
        if((*it)->index==u){
            vNodes.erase(it);
            break;
        }
    }
}

int numGraphs(const std::unordered_map<int, Node*>& graph){
    std::unordered_set<Node*> allNodes;
    for(const auto& node:graph){
        allNodes.insert(node.second);
    }
    std::unordered_set<Node*> passedNodes;
    std::queue<Node*> nodesNeedToPass;
    int numGraphs=0;
    while(!allNodes.empty()){
        numGraphs++;
        passedNodes.clear();
        nodesNeedToPass.push(*(allNodes.begin()));
        passedNodes.insert(nodesNeedToPass.front());
        while(!nodesNeedToPass.empty()){
            Node* curr = nodesNeedToPass.front();
            allNodes.erase(curr);
            nodesNeedToPass.pop();
            for(const auto& child:curr->nodes){
                if(passedNodes.find(child)==passedNodes.end()){
                    passedNodes.insert(child);
                    nodesNeedToPass.push(child);
                }
            }
        }
    }
    return numGraphs;
}

int main()
{
    int numNodes, numRebra, numCuts;
    std::cin >> numNodes >> numRebra;
    std::unordered_map<int, Node*> graph;
    std::unordered_set<Node*> allNodes;
    std::vector<std::vector<int>> adjMtx(numRebra);
    std::vector<int> cuts;
    for(int i=0;i<numRebra;i++){
        adjMtx[i].resize(2);
        std::cin >> adjMtx[i][0] >> adjMtx[i][1];
    }

    std::cin >> numCuts;
    cuts.resize(numCuts);

    for(int i=0;i<numCuts;i++){
        std::cin >> cuts[i];
    }

    for(size_t i=0;i<numNodes;i++){
        graph[i] = new Node(i+1);
    }
    adjToGraph(adjMtx, graph);
    for(int i=0;i<numCuts;i++){
        removeRebro(adjMtx, graph, cuts[i]);
        std::cout << numGraphs(graph) << ' ';
    }
    
    return 0;
}
