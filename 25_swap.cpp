#include <iostream>
#include <string>

template <class T>//关键字class并不意味着这个是类哦，这只是一种约定俗成的写法。
//字母T将在接下来的函数里代表一种不确定的数据类型。
//template <typename T>来代替template <class T>，它们的含义是一样一样的。
//template <class T>中的class并不意味着T只能是一个类
void swap(T &a, T &b) //函数模板，T表示类型
{
    T tem = a;
    a = b;
    b = tem;
}
int main()
{
    int i1 = 100;
    int i2 = 200;
    std::cout << "i1 " << i1 << " j2" << i2 << "\n";
    swap(i1, i2);
    //如果这里要明确使用某一种类型的变量，
    //则用swap<int>(i1,i2),尖括号里面是数的类型
    std::cout << "i1 " << i1 << "j2 " << i2 << "\n";
    std::string a1 = "asfedas";
    std::string a2 = "dfgcsx";
    std::cout << "a1 " << a1 << "a2 " << a2 << "\n";
    swap(i1, i2);
    std::cout << "a1 " << a1 << "a2 " << a2 << "\n";
    return 0;
}
/*
执行结果：
i1 100 j2200
i1 200j2 100
a1 asfedasa2 dfgcsx
a1 asfedasa2 dfgcsx
*/