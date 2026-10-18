#include <iostream>

bool isSimp(int n){
    if (n<2) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    
    for(int i=3;i*i<=n;i+=2){
        if (n%i==0) return false;
    }
    return true;
}


int main()
{
    int m, n, k=0;
    std::cin >> m >> n;
    for(int i=m;i<=n;i++){
        if(isSimp(i)){
            std::cout << i << '\n';
            k++;
        }
    }
    if(k==0){
        std::cout << "Absent\n";
    }
    return 0;
}
