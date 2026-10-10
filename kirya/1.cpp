#include <iostream>
#include <list>

int main()
{
    int numComms, comm, val, index;
    std::cin >> numComms;
    std::list<int> stroy;
    for(int i=0;i<numComms;i++){
        std::cin >> comm >> val;
        auto iter = stroy.begin();
        if(comm==1){
            index=0;
            auto iter = stroy.begin();
            while(iter != stroy.end() && *iter >= val){
                iter++;
                index++;
            }
            stroy.insert(iter, val);
            std::cout << index << '\n';
        }
        else if(comm==2){
            for(int i=0;i<val;i++){
                iter++;
            }
            stroy.erase(iter);
        }
    }
    return 0;
}
