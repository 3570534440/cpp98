#include <iostream>
int *newint(int);
int main()
{
    int *x = newint(20);
    std::cout << *x;
    delete x;
    x = NULL;
    return 0;
}
int *newint(int a)
{
    int *b = new int;
    *b = a;
    return b;
}
/*
执行结果：

20
*/