#include <iostream>
#include <string>

class Pet
{
public:
	Pet(std::string theName);
	//析构器都是虚方法
	virtual void eat();//有对eat的定义
	virtual void sleep();//有对sleep的定义
	virtual void play() = 0;//调用时不执行这一行//没有对play的定义，子类有

protected:
	std::string name;//这个类的本身可以访问它
};

class Cat : public Pet
{
public:
	Cat(std::string theName);

	void climb();
	void play();
};

class Dog : public Pet
{
public:
	Dog(std::string theName);

	void bark();
	void play();
};

Pet::Pet(std::string theName)
{
	name = theName;
}

void Pet::eat()
{
	std::cout << name << "正在吃东西!\n";
}

void Pet::sleep()
{
	std::cout << name << "正在睡大觉!\n";
}

Cat::Cat(std::string theName) : Pet(theName)
{
}

void Cat::climb()
{
	std::cout << name << "正在爬树!\n";
}

void Cat::play()
{
	std::cout << name << "玩毛线球!\n";
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

void Dog::bark()
{
	std::cout << name << "旺~旺~\n";
}

void Dog::play()
{
	std::cout << name << "正在追赶那只该死的猫!\n";
}

int main()
{
	Pet *cat = new Cat("加菲");
	Pet *dog = new Dog("欧迪");

	cat -> sleep();
	cat -> eat();
	cat -> play();

	dog -> sleep();
	dog -> eat();
	dog -> play();

	delete cat;
	delete dog;

	return 0;
}
/*执行结果
加菲正在睡大觉!
加菲正在吃东西!
加菲玩毛线球!
欧迪正在睡大觉!
欧迪正在吃东西!
欧迪正在追赶那只该死的猫!
*/