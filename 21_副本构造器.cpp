#include <iostream>
#include <string>

class Maclass
{
public:
    Maclass(int *p);
    ~Maclass();

    Maclass &operator=(const Maclass &rhs);
    //该函数返回一个引用，该引用指向一个Maclass的对象
    //输入参数是一个Maclass的类型，不可被改变的类型
    //这里只需要读取这个参数，而不要改变它的值
    void print();

private:
    int *ptr;
};
Maclass::Maclass(int *p)
{
    ptr = p; //ptr这个指针指向1和2
}
Maclass::~Maclass()
{
    delete ptr;
}
Maclass &Maclass::operator=(const Maclass &rhs)
{                     //条件一 ： 对象赋值 赋值号两边为不同的对象    a=b; (a为本对象,b为传入的对象)
    if (this != &rhs) //传入的是b的地址，看是否和a的地址相等
    {                 //判断重载函数右操作数传入的对象的引用是否和本类对象的地址一致
                      //this指针指向了第一个内存块的地址，也就是a的地址,&rhs是b的地址
        delete ptr;   //如果不一致，说明要复制的对象和原来的对象不相等
        //此时释放a对象ptr指针

        ptr = new int;   //开辟一个新的内存块的地址给a的ptr
        *ptr = *rhs.ptr; //将b的ptr赋值给a的ptr
    }
    else
    {
        std::cout << "asfasfe";
    }
    return *this;
}
void Maclass::print()
{
    std::cout << *ptr << std::endl;
}
int main()
{
    Maclass obj1(new int(1));
    /* 可以在new后面直接赋值
    int *p = new int(3);
    也可以单独赋值
    *p = 3;
    如果不想使用指针，可以定义一个变量，在new之前用“*”表示new出来的内容
    int q = *new int;
    q = 1;
    cout << q << endl;
    //当new一个数组时，同样用一个指针接住数组的首地址
    int *q = new int[3];
    for(int i=0; i<3; i++)
    q[i] = i;
    //这里是用一个结构体指针接住结构体数组的首地址
    //对于结构体指针，个人认为目前这种赋值方法比较方便
    student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
   */
    Maclass obj2(new int(2));
    obj1.print();
    obj2.print();
    obj1 = obj2;
    obj1.print();
    obj2.print();
    return 0;
}