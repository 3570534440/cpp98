#include <iostream>
#include <climits>

unsigned long returnFactorial(unsigned short num);

int main()
{
    unsigned short num = 0;

    std::cout << "请输入一个整数: ";
    while( !(std::cin>>num) || (num<1) )
    {
        std::cin.clear();             // 清除状态
        std::cin.ignore(100, '\n');   // 清除缓冲区
        std::cout << "请输入一个整数：";
    }
    std::cin.ignore(100, '\n');

    try
    {
        unsigned long factorial = returnFactorial(num);
        std::cout << num << "的阶乘值是: " << factorial;
    }
    catch(const char *e)
    {
        std::cout << e;
    }

    return 0;
}

unsigned long returnFactorial(unsigned short num) {
    unsigned long sum = 1;
    unsigned long max = ULONG_MAX;

    for( int i=1; i <= num; i++ )
    {
        sum *= i;
        max /= i;
    }

    if( max < 1 )
    {
        throw "悲催。。。该基数太大，无法在该计算机计算求出阶乘值。\n";
    }
    else
    {
        return sum;
    }
}

/*
执行结果：
请输入一个整数: 15
15的阶乘值是: 1307674368000
*/