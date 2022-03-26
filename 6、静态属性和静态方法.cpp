#include <iostream>
#include <string>

class Pet
{
public:
    Pet(std::string theName);
    ~Pet();
    //静态方法不属于某个特定的对象，所以他们不能访问this指针
    static int getCount();
    //定义静态函数。
    //静态函数里面只能有静态变量

protected:
    std::string name;
    //pet类可以访问name
private:
    static int count;
    //pet类可以访问count
    //静态成员属性，在类外面初始化
    //count在静态成员空间，用来计数
    //可以看作所有pet对象共享的的量
    //在main函数之前count已经有值
};

class Dog : public Pet
{
public:
    Dog(std::string theName);
};

class Cat : public Pet
{
public:
    Cat(std::string theName);
};

int Pet::count = 0;
// 计数，在静态存储区，初始化为0
//pet类中的count初始化为0，用::作用域操作符

Pet::Pet(std::string theName)
{
    name = theName;
    count++;

    std::cout << "name is " << name << "\n"; //第一步和第二步，先是两个构造器
                                             //每执行一次count加一，所以等于二
}

Pet::~Pet() //析构器                        //最后执行析构器，count--
{
    count--;
    std::cout << name << "died\n";
}

int Pet::getCount()
//这个接口函数的唯一作用把返返回
//调用静态函数
//调用时用类名::对象名，而不是用.号。
{
    return count;
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

Cat::Cat(std::string theName) : Pet(theName)
{
}

int main()
{
    Dog dog("Tom"); //创建对象dog，自动传参，调用函数
    Cat cat("Jerry");
    //Dog dog=cat;//可以这样赋值，将cat对象赋给dog对象
    //此时会调用复制构造函数，这个函数系统会自动生成

    std::cout << "\nappear" << Pet::getCount() << "animal!\n\n"; //第三步，打印两只anlmal//里面是一个解析器
    {

        Dog dog_2("Tom_2");
        Cat cat_2("Jerry_2");

        std::cout << "\nsecond appear" << Pet::getCount() << "animal!\n\n";
    } //大括号之后执行析构器

    std::cout << "\nthere have " << Pet::getCount() << " animal!\n\n"; //最后执行最后的喜析构器

    return 0;
}