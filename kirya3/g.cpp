#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    int numNodes, numEdges, numConc;
    long long inf = LLONG_MIN/2;
    std::cin >> numNodes >> numEdges >> numConc;

    std::vector<std::vector<long long>> dists(numNodes, std::vector<long long>(numNodes, inf));
    std::vector<std::vector<std::pair<int,int>>> next(numNodes, std::vector<std::pair<int,int>>(numNodes, {-1, -1}));
    std::vector<int> path;
    std::vector<int> concs(numConc);

    int city1, city2;
    long long ves;
    for(int i=0;i<numNodes;i++)
        dists[i][i]=0;

    for(int i=0;i<numEdges;i++){
        std::cin >> city1 >> city2 >> ves;
        city1--;city2--;
        if(ves>dists[city1][city2]){
            dists[city1][city2]=ves;
            next[city1][city2] = {city2, i};
        }
    }

    for(int i=0;i<numConc;i++){
        std::cin >> concs[i];
        concs[i]--;
    }

    long long cyclNum = LLONG_MAX/4;
    long long d;
    for(int k=0;k<numNodes;k++){
        for(int i=0;i<numNodes;i++){
            if(dists[i][k] == inf) continue;
            for(int j=0;j<numNodes;j++){
                if(dists[k][j] == inf) continue;
                d = dists[i][k]+dists[k][j];
                if(d>cyclNum) d=cyclNum;
                if(d>dists[i][j]){
                    dists[i][j]=d;
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    std::vector<int> infcycl;
    for(int i=0;i<numNodes;i++){
        if(dists[i][i]!=0){
            infcycl.push_back(i);
        }
    }
    int from, to;
    if(!infcycl.empty()){
        for(int i=0;i<numConc-1;i++){
            from = concs[i];
            to = concs[i+1];
            for(int v:infcycl){
                if(dists[from][v]!=inf && dists[v][to]!=inf){
                    std::cout << "infinitely kind\n";
                    return 0;
                }
            }
        }
    }

    int curr, target;
    for(int i=0;i<numConc-1;i++){
        curr = concs[i];
        target = concs[i+1];

        while(curr!=target){
            auto [node, edge] = next[curr][target];
            path.push_back(edge);
            curr = node;
        }
    }
    std::cout << path.size() << '\n';
    if(!path.empty()){
        for(int i=0;i<path.size();i++){
            std::cout << path[i]+1;
            if(i!=path.size()-1){
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
