#include <iostream>
#include<string>
int main()
{
    std::string str;
    std::cout<<"please in put"<<"\n";
    std::getline(std::cin,str);//记住空格；
    std::cout<<str<<"\n";
    return 0;
}