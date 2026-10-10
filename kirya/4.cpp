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


int main()
{
    int numNodes, numRebra;
    std::cin >> numNodes >> numRebra;
    std::unordered_map<int, Node*> graph;
    std::vector<std::vector<int>> adjMtx(numRebra);
    for(int i=0;i<numRebra;i++){
        adjMtx[i].resize(2);
        std::cin >> adjMtx[i][0] >> adjMtx[i][1];
    }

    for(size_t i=0;i<adjMtx.size();i++){
        graph[i] = new Node(i);
    }

    for(size_t i=0;i<adjMtx.size();i++){
        for(size_t j=0;j<adjMtx[i].size();j++){
            if(i!=adjMtx[i][j]-1){
                graph[i]->addChild(graph[adjMtx[i][j]-1]);
                graph[adjMtx[i][j]-1]->addChild(graph[i]);
            }
        }
    }

    std::unordered_set<Node*> passedNodes;
    std::queue<Node*> nodesNeedToPass;

    nodesNeedToPass.push((*(graph.begin())).second);
    while(!nodesNeedToPass.empty()){
        Node* curr = nodesNeedToPass.front();
        nodesNeedToPass.pop();
        for(int i=0;i<curr->nodes.size();i++){
            nodesNeedToPass.push(curr->nodes[i]);
        }
    }

    return 0;
}
