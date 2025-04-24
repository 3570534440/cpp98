#include <iostream>
#include <string>

class Pet
{
public:
	Pet(std::string theName);
	//析构器都是虚方法
	void eat();
	void sleep();
	virtual void play(); //虚方法

protected:
	std::string name;
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
	std::cout << name << "eatingg!\n";
}

void Pet::sleep()
{
	std::cout << name << "sleeping!\n";
}

void Pet::play()
{
	std::cout << name << "playing!\n";
}

Cat::Cat(std::string theName) : Pet(theName)
{
}

void Cat::climb()
{
	std::cout << name << "play play!\n";
}

void Cat::play()
{
	Pet::play();
	std::cout << name << "play playing!\n";
}

Dog::Dog(std::string theName) : Pet(theName)
{
}

void Dog::bark()
{
	std::cout << name << "goto\n";
}

void Dog::play()
{
	Pet::play();
	std::cout << name << "cat!\n";
}

int main()
{
	Pet *cat = new Cat("jiafei  "); //因为是pet类型的指针，所以cat里面的play没有覆盖pet里面的play
	Pet *dog = new Dog("x.dfsd  ");

	cat->sleep();
	cat->eat();
	cat->play();   //子类可以再调用父类的play，然后再执行自己的

	dog->sleep();
	dog->eat();
	dog->play();

	delete cat;
	delete dog;

	return 0;
}

/*执行结果   
jiafei  sleeping!
jiafei  eatingg!
jiafei  playing!
jiafei  play playing!
x.dfsd  sleeping!
x.dfsd  eatingg!
x.dfsd  playing!
x.dfsd  cat!
*/