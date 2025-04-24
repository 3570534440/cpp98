#include <iostream>
#include <string>
class Baseclass
{
public:
    Baseclass();  //构造器
    ~Baseclass(); //析构器

    void dosomething();
};

class Subclass : public Baseclass
{
public:
    Subclass();
    ~Subclass();
};
Baseclass::Baseclass()
{
    std::cout << "aaaaaaa\n"
              << std::endl; //第一步
    std::cout << "bbbbbbb\n"
              << std::endl;
}
Baseclass::~Baseclass()
{
    std::cout << "ccccccc\n"
              << std::endl; //第六步
    std::cout << "ddddddd\n"
              << std::endl;
}
void Baseclass ::dosomething()
{
    std::cout << "eeeeeee\n"
              << std::endl; //第三步
}
Subclass::Subclass()
{
    std::cout << "fffffff\n"
              << std::endl; //第二步
}
Subclass::~Subclass()
{
    std::cout << "ggggggg\n"
              << std::endl; //第五步
}
int main()
{ //执行顺序，父类的构造函数，子类的构造函数，子类的析构函数 ，父类的析构函数
    Subclass subclass;
    subclass.dosomething();
    std::cout << "ok" << std::endl; //第四步

    return 0;
}