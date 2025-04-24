#include <iostream>
#include <string>

template <class T>
class Stack
{
public:
    Stack(unsigned int size = 100);
    ~Stack();

    void push(T value); // 把 value 推入栈中
    T pop();            // 弹出栈顶元素

private:
    unsigned int size; // 栈容量
    unsigned int sp;   // 栈指针（栈顶索引）
    T *data;           // 栈数据数组
};

template <class T>
Stack<T>::Stack(unsigned int size)
{
    this->size = size;
    data = new T[size];
    sp = 0;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <class T>
void Stack<T>::push(T value)
{
    if (sp < size)
    {
        data[sp++] = value;
    }
    else
    {
        std::cout << "Stack Overflow!\n";
    }
}

template <class T>
T Stack<T>::pop()
{
    if (sp > 0)
    {
        return data[--sp];
    }
    else
    {
        std::cout << "Stack Underflow!\n";
        return T(); // 返回默认值
    }
}

int main()
{
    Stack<int> com(15);   
//这个 T 是一个占位符，表示这个类是模板的，只有等你使用的时候，告诉它具体用什么类型代替 T，它才会生成真正的类。此时用int代替 T
    com.push(42);
    com.push(7);

    std::cout << "弹出元素: " << com.pop() << "\n";
    std::cout << "弹出元素: " << com.pop() << "\n";
    std::cout << "弹出元素: " << com.pop() << "\n"; // 栈空测试

    return 0;
}
