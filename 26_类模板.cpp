#include <iostream>
#include <string>

template <class T>
//类模板与函数模板非常相似：同样是先由你编写一个类的模板，
//再由编译器在你第一次使用这个模板时生成实际代码
class Stack
{
public:
    Stack(unsigned int size = 100);
    ~Stack();
    void push(T value); //吧value推进栈里
    T pop;

private:  
    unsigned int size; //声明栈的尺寸
    unsigned int sp;
    T *date;
};
template <class T>
Stack<T>::Stack(unsigned int size) //构造器，<T>用T来占用一个位置，是占位符
{
    this->size = size;
    date = new T(size);
    sp = 0;
};
int main()
{
    Stack<int> com(15);
    com.push();
}