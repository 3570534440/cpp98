#include <iostream>
#include <string>
class Myclass
{
public:
    Myclass(int *p);
    Myclass(const Myclass &rhs);
    ~Myclass();

    Myclass &operator=(const Myclass &rhs);
    void print();

private:
    int *ptr;
};
Myclass::Myclass(int *p)
{
    std::cout << "go 1\n\n";
    ptr = p;
    std::cout << "out 1\n\n";
}
Myclass::Myclass(const Myclass &rhs)
{
    std::cout << "go 2\n\n";
    *this = rhs;
    std::cout << "out 2\n\n";
}
Myclass::~Myclass()
{
    std::cout << "go 3\n\n";
    delete ptr;
    std::cout << "out 3\n\n";
}
Myclass &Myclass::operator=(const Myclass &rhs)
{
    std::cout << "go 4\n\n";
    if (this != &rhs)
    { 
        delete ptr;

        ptr = new int;
        *ptr = *rhs.ptr;
    }
    else
    {
        std::cout << "asgewsg\n\n";
    }
    std::cout << "out out\n\n";
    return *this;
}
void Myclass::print()
{
    std::cout << *ptr << std::endl;
}
int main()
{
    Myclass obj1(new int(1));
    Myclass obj2(new int(2));
    obj1 = obj2;
    obj1.print();
    obj2.print();

    std::cout << "-------------------";
    Myclass obj3(new int(3));
    Myclass obj4 = obj3;
    obj3.print();
    obj4.print();
    std::cout << "-------------------";

    Myclass obj5(new int(5));
    obj5 = obj5;
    obj5.print();

    return 0;
}
