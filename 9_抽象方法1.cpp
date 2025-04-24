#include <iostream>

class ClxBase
{
public:
    ClxBase(){};

    virtual ~ClxBase() //必须声明虚方法，
        //如果不声明，则调用基类的，因为调用的是子类的函数，这样子类的析构器就不能被调用了
        //析构器目的是为了释放内存的资源，否则会造成资源的浪费
        {};

    void doSomething()
    //抽象函数就是纯虚函数，让它等于0，代表只有子类才有对这个函数的声明
    {
        std::cout << "Do something in class ClxBase!\n";
    }
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived(){};

    ~ClxDerived()
    {
        std::cout << "Output from the destructor of class ClxDerived!\n";
    };

    void doSomething()
    {
        std::cout << "Do something in class ClxDerived!\n";
    };
    //如果不想执行，则要设置为虚函数
    // virtual void doSomething()
    // {
    //     std::cout << "Do something in class ClxBase!\n";
    // }
};

int main()
{
    ClxBase *pTest = new ClxDerived;

    pTest->doSomething(); //执行父类的doSomething

    delete pTest;         //执行子类的析构

    return 0;
}

/*执行结果 ，这里执行的是父类的doSomething,因为他不是虚函数，如果要执行子类的，则需要设置为
Do something in class ClxBase!
Output from the destructor of class ClxDerived!
*/