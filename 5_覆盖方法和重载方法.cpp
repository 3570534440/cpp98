#include <iostream>
#include <string>
class Animal
{
public:
    Animal(std::string theName);
    void eat();
    void eat(int eatCount); //相同函数名，不同参数
    void sleep();
    void drool();

protected:
    std::string name;
};

class Pig : public Animal
{
public:
    Pig(std::string theName);
    void climb();
};

class Turtle : public Animal
{
public:
    Turtle(std::string theName);
    void swim();
};

Animal::Animal(std::string theName) //最先是解析器，
{
    name = theName;
}

void Animal::eat()
{
    std::cout << "I'm eatting!" << std::endl; //第一步，第二步
}

void Animal::eat(int eatCount)
{
    std::cout << "i eating" << eatCount << "lunch!\n\n"; //第三步
}

void Animal::sleep()
{
    std::cout << "I'm sleeping!Don't disturb me!\n"
              << std::endl;
}

void Animal::drool()
{
    std::cout << "i am man\n"
              << std::endl;
}

Pig::Pig(std::string theName) : Animal(theName) //第二个解析器
{
}

void Pig::climb() //第四步
{
    std::cout << "i am beautiful gile\n"
              << std::endl;
}

Turtle::Turtle(std::string theName) : Animal(theName) //第三个解析器
{
}

void Turtle::swim() //第五步
{
    std::cout << "i am a flish\n"
              << std::endl;
}

int main()
{
    Pig pig("pig");
    Turtle turtle("flish");

    // std::cout << "这只猪的名字是: " << pig.name << std::endl;                // 错误
    // std::cout << "每只乌龟都有个伟大的名字: " << turtle.name << std::endl;   // 错误

    pig.eat();
    turtle.eat();

    pig.eat(15);
    pig.climb();
    turtle.swim();
    //最后执行三个构造器，基类的构造器在最后
    return 0;
}
/*
执行结果
I'm eatting!
I'm eatting!
i eating15lunch!

i am beautiful gile

i am a flish
*/