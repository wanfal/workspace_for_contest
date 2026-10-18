#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> table(n);
    for(int i=0;i<n;i++){
        table[i].resize(3);
        std::cin >> table[i][0] >> table[i][1];
        table[i][2] = table[i][0] + table[i][1];
    }

    std::sort(table.begin(), table.end(), [](const auto& a, const auto& b) {
        if (a[2] != b[2]) return a[2] > b[2];
        return a[0] > b[0];
    });

    long long sum=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            sum+=table[i][0];
        }
        else{
            sum-=table[i][1];
        }
    }

    std::cout << sum << '\n';
    return 0;
}
