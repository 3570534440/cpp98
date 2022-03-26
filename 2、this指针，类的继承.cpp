#include <iostream>
#include <string>
class Animal //定义基类
{
public:
    std::string mouth;

    void eat();   //this指针存在与类的非静态函数中//自动生成，自动隐藏
    void sleep(); //当一个对象被创建时，该对象的this指针就指向该对象数据的首地址
    void drool();
};
class Pig : public Animal //前面的类继承后面的类,子类
{
public:
    void climb();
};
class Turtle : public Animal //子类
{
public:
    void swim();
};
void Animal::eat() //调用函数
{
    std::cout << "i am eating\n"
              << std::endl;
}
void Animal::sleep()
{
    std::cout << "i am sleeping ,don't disturb me\n"
              << std::endl;
}
void Animal::drool()
{
    std::cout << "nonononon\n"
              << std::endl;
}
void Pig::climb() //pig 继承animal ,所以animal有的pig也有
{
    std::cout << "it is pig," << std::endl;
}
void Turtle::swim()
{
    std::cout << "i am swimming" << std::endl;
}
int main()
{
    Pig pig;       //前面是子类，用子类定义一个名字
    Turtle turtle; //必须定义名字

    pig.eat(); //直接调用函数
    turtle.eat();
    pig.climb();
    turtle.swim();

    return 0;
}