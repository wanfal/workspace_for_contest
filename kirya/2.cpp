#include <iostream>
#include <vector>
#include <algorithm>

struct Order{
    int day;
    int dengi;
    bool operator>(const Order& other)const{
        if(this->dengi>other.dengi){
            return true;
        }
        return false;
    }
    bool operator<(const Order& other)const{
        if(this->dengi<other.dengi){
            return true;
        }
        return false;
    }
};

bool compare(const Order& left, const Order& right) 
{ 
    return left > right; 
}

int main()
{
    int numOrders, resSum=0, maxDay=0;
    std::cin >> numOrders;
    std::vector<Order> orders(numOrders);
    for(int i=0;i<numOrders;i++){
        std::cin >> orders[i].day >> orders[i].dengi;
        if(maxDay<orders[i].day){
            maxDay = orders[i].day;
        }
    }
    
    std::sort(orders.begin(), orders.end(), compare);

    std::vector<bool> busy(maxDay+1, false);

    for (const auto& ord:orders) {
        for (int j=ord.day;j>=1;j--) {
            if(!busy[j]){
                busy[j] = true;
                resSum += ord.dengi;
                break;
            }
        }
    }
    std::cout << resSum << '\n';
    return 0;
}
