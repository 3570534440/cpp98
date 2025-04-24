#include <iostream>
#include <string>

class Complay
{
public:
    Complay(std::string thename, std::string product);
    virtual void printinfo();

protected:
    std::string name;
    std::string product;
};
class Techcomply : public Complay
{
public:
    Techcomply(std::string thename, std::string product);
    virtual void printinfo();
};


Complay::Complay(std ::string thename, std::string product)
{
    name = thename;
    this->product = product; //用this指针区别成员和参数
}
void Complay::printinfo()
{
    std::cout << "complay is " << name << "product" << product << std::endl;
}
Techcomply::Techcomply(std::string thename, std::string product) : Complay(thename, product)
{
}
void Techcomply::printinfo()
{
    std::cout << name << "product" << product << "this";
}
int main()
{
    Complay *complay = new Techcomply("apple", "iphone"); //类型不同
    Techcomply *techcomply = (Techcomply *)complay;
    //所以要类型转化，用Techcomply强制转化，techcomply*类型

    techcomply->printinfo();
    delete complay; //只需要delete其中的一个地址，因为两个地址指向一个地方
    //delete techcomply;//不能两次释放同一个地址
    complay = NULL;
    techcomply = NULL;
    return 0;
}