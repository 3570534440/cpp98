#include <iostream>
#include <string>
int main()
{
    unsigned int count = 0;
    std::cout << "place input score";
    std::cin >> count;
    int *x = new int[count]; //要申请的地址大小是count
    for (int i = 0; i < count; i++)
    {
        x[i] = i; //x[i]=*(x+i)
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << "x[i"
                  << "]is" << x[i] << "\n";
    }
    return 0;
}