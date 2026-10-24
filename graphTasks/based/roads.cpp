#include <iostream>
#include<vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int mtxSize, numRoads=0;
    std::cin >> mtxSize;
    std::vector<int> row(mtxSize);
    for(int i=0;i<mtxSize;i++){
        for(int j=0;j<mtxSize;j++){
            std::cin >> row[j];
        }
        for(int j=i;j<mtxSize;j++){
            if(row[j]==1){
                numRoads++;
            }
        }
    }

    std::cout << numRoads << '\n';

    return 0;
}
