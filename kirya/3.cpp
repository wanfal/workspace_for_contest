#include <iostream>

struct Time
{
    int h;
    int m;
    Time& operator++(int){
        this->h++;
        if(h>23){
            h=0;
        }
        return *this;
    }
};

int normikTime(int h){
    if(h==0 || h==12){
        return 12;
    }
    if(h > 12){
        return h-12;
    }
    return h;
}

int toMin(Time t){
    return t.h*60 + t.m;
}

int main()
{
    Time start, end;
    int res=0;
    std::cin>>start.h>>start.m;
    std::cin>>end.h>>end.m;

    int s = toMin(start);
    int e = toMin(end);
    if(e<=s){
        e += 24*60;
    }

    int curr = s;
    if(curr % 30 == 0){
        curr += 30;
    } 
    else{
        curr = ((curr / 30) + 1) * 30;
    }

    while(curr <= e){
        int h = (curr/60) % 24;
        int m = curr%60;
        if(m==0){
            res += normikTime(h);
        } 
        else{
            res++;
        }
        curr+=30;
    }

    std::cout<<res;
    return 0;
}