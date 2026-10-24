#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> p(n);

    for(int i=0;i<n;i++){
        std::cin>>p[i];
    }

    int i=0, j=1, k=0, a, b;
    while(i<n && j<n && k<n){
        a = p[(i+k)%n];
        b = p[(j+k)%n];

        if(a==b){
            k++;
        } 
        else if(a<b){
            j=j+k+1;
            k=0;
        } 
        else{
            i=i+k+1;
            if(i<=j){
                i=j+1;
            }
            k=0;
        }
    }

    int start = std::min(i, j);
    if (start>=n) start=0;

    for(int i=0;i<n;i++){
        std::cout << p[(start+i)%n];
        if(i!=n-1){
            std::cout << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
