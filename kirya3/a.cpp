#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, c, res=0;
    std::cin >> n;
    std::vector<int> lst(1000000, 0);
    std::string op;
    for(int i=0;i<n;i++){
        std::cin >> op >> c;
        if(op == "add"){
            while(lst[c]==1){
                lst[c]=0;
                c++;
                res--;
            }
            lst[c]=1;
            res++;
        }
        else{
            while(lst[c]==0){
                lst[c]=1;
                c++;
                res++;
            }
            lst[c]=0;
            res--;
        }
        std::cout << res << '\n';
    }
    return 0;
}
