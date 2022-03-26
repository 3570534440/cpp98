#include<iostream>
#include<string>
class Animal//类第一个字母大写
{
    public://开放的，若任何代码都可访问
    Animal(std::string thename);
    //返回值是thename
    //析构器，析构器与名字相同，
    //作用初始化
    void eat();
    void sleep();
    void drool();

    //protected://这个类本身和它的子类可以访问
    //private:只有这个类本身可以访问
    //继承来的每一个成员都当成private来对待
    //只有它的子类可以使用它从基类继承来的元素
    std::string name;
};//只有类后面有分号
class Pig:public Animal
{
    public:
    void climb();
    Pig(std::string thename);//析构器
};
class Turtle:public Animal
{
    public:
    void swim();
    Turtle (std::string thename);//析构器
};
Animal::Animal(std::string thename)
{
    name=thename;
}
void Animal::eat()
{
    std::cout<<"aaaaa"<<std::endl;
}
void Animal::sleep()
{
    std::cout<<"bbbbb"<<std::endl;
}
void Animal:: drool()
{
    std::cout<<"eeeee"<<std::endl;
}

Pig::Pig(std::string thename):Animal(thename)
//初始化，使pig.name继承到animal中的thename
//便于给pig.name赋值
{
}

void Pig::climb()
{
    std::cout<<"fffff"<<std::endl;
}

Turtle::Turtle(std::string thename):Animal(thename)
{
}
void Turtle::swim()
{
    std::cout<<"ggggg"<<std::endl;
}
int main()
{
    Pig pig("hhhh");//初始化，子类可以访问基类，可以这样赋值
    Turtle turtle("iiii");//初始化，两个子类的值可以分开，可以不同
    pig.name="jjjjj";//赋值
    std::cout<<pig.name<<std::endl;
    std::cout<<turtle.name<<std::endl;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();
    return 0;
}