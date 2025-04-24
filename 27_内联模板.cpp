/*                                   内联函数

*/

//inline int add(int x,int y,int z)
//{
 //   return x+y+z;
//}//内敛模板
//调用其函数时，该函数在编译时被替代，而不像一般函数那样是在运行时被调用。
// 
//引入内联函数的目的是为了解决程序中函数调用的效率问题。
//类似宏替换，使用函数体替换调用处的函数名。

#include<iostream>
#include<string>

template <class T>
class Stack
{
    public:
    Stact(std::string size =100);
    {
        this->size=size;
        date=new T[size];
        sp=0;
    }    
    ~Stack();
    {
        delete []date;
    }
    void push(T value);    
    {
        date[sp++]=value;
    }
    T pop();
    {
        return date[--sp];
    }
    private:
    unsigned int size;
    unsigned int sp;
    T *date;

};
