#include <iostream>
#include <string>

int main()
{
    std::string str1, substr;
    std::cin >> str1;
    std::cin >> substr;
    int lenSubStr = substr.length(), lenStr = str1.length();


    for(int i=0;i<lenStr-lenSubStr+1;i++){
        if(str1.compare(i, lenSubStr, substr)==0){
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
