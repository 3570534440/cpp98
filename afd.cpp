#include <iostream>
#include <string>

template <class T>
class Stack
{
public:
    Stack(unsigned int mo);
    ~Stack();
    void push(T a)
        t pop();

private:
    T *a;
    unsigned int mo;
    unsigned int book;
    unsigned int fp;
};
template <class T>
Stack<T>::Stack(unsigned int mo)
{
    this->mo = mo;
}
template <class T>
void Stack<T>::push(T a)
{
    a[mo++] =
}
template <class T>
T Stack<T>::pop()
{
}
template <class T>
Stack<T>::~Stack()
{
    delete[] a;
}
int main()
{
    Stack<int> possable(15);
    Stack<double> possable(25);

    possable.push(2);
    std::cout << "asdf" << std::endl;
}
