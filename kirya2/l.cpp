#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int n;
    std::cin >> n;
    std::vector<std::vector<long long>> k;
    for(int i=0;i<n;i++){
        int t, w;
        std::cin >> t >> w;
        k.push_back({w, t, i});
    }

    std::sort(k.begin(), k.end());

    for(int i=0;i<(int)k.size();i++){
        k[i] = {k[i][2], 1LL*k[i][0]*k[i][1]};
    }

    int last_time=-1;

    for(int i=0;i<k.size();i++){
        if(last_time==-1){
            last_time = k[i][1];
        } 
        else{
            if(k[i][1]<=last_time){
                k[i][1] = last_time;
            } 
            else{
                last_time = k[i][1];
            }
        }
    }
    std::sort(k.begin(), k.end());

    for(auto &i:k){
        std::cout << i[1] << "\n";
    }

    return 0;
}