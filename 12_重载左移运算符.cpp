#include <iostream>
#include <string>
#include <stdlib.h>

class Rational
{
public:
    Rational(int num, int denom);  // num = 分子, denom = 分母

    Rational operator+(Rational rhs); // rhs == right hand side
    Rational operator-(Rational rhs);
    Rational operator*(Rational rhs);
    Rational operator/(Rational rhs);

private:
    void normalize(); // 负责对分数的简化处理

    int numerator;    // 分子
    int denominator;  // 分母

    friend std::ostream& operator<<(std::ostream& os, Rational f);
    //重载的左移操作符不是rational类的一部分，
    //但是它需要访问到这个类的一个private的私有成员
};

Rational::Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;

    normalize();
}

// normalize() 对分数进行简化操作包括：
// 1. 只允许分子为负数，如果分母为负数则把负数挪到分子部分，如 1/-2 == -1/2
// 2. 利用欧几里德算法（辗转求余原理）将分数进行简化：2/10 => 1/5
void Rational::normalize()
{
    // 确保分母为正
    if( denominator < 0 )
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    // 欧几里德算法
    int a = abs(numerator);
    int b = abs(denominator);

    // 求出最大公约数
    while( b > 0 )
    {
        int t = a % b;
        a = b;
        b = t;
    }

    // 分子、分母分别除以最大公约数得到最简化分数
    numerator /= a;
    denominator /= a;
}

// a   c   a*d   c*b   a*d + c*b
// - + - = --- + --- = ---------
// b   d   b*d   b*d =    b*d
Rational Rational::operator+(Rational rhs)
{
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    int e = a*b + c*d;
    int f = b*d;

    return Rational(e, f);
}

// a   c   a   -c
// - - - = - + --
// b   d   b   d
Rational Rational::operator-(Rational rhs)
{
    rhs.numerator = -rhs.numerator;

    return operator+(rhs);
}

// a   c   a*c
// - * - = ---
// b   d   b*d
Rational Rational::operator*(Rational rhs)
{
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    int e = a*c;
    int f = b*d;

    return Rational(e, f);
}

// a   c   a   d
// - / - = - * -
// b   d   b   c
Rational Rational::operator/(Rational rhs)
{
    int t = rhs.numerator;
    rhs.numerator = rhs.denominator;
    rhs.denominator = t;

    return operator*(rhs);
}

std::ostream& operator<<(std::ostream& os, Rational f);
//先是这个类的声明
//只要是属于rational就执行重载后的函数
int main()
{
    Rational f1(2, 16);  //初始化 对分数进行简化操作包括：
    Rational f2(7, 8);

    // 测试有理数加法运算
    std::cout << f1 << " + " << f2 << " == " << (f1+f2) << "\n";
    //相加之后是一个tational的对象，就调用外部函数
    // 测试有理数减法运算
    std::cout << f1 << " - " << f2 << " == " << (f1-f2) << "\n";

    // 测试有理数乘法运算
    std::cout << f1 << " * " << f2 << " == " << (f1*f2) << "\n";

    // 测试有理数除法运算
    std::cout << f1 << " / " << f2 << " == " << (f1/f2) << "\n";

    return 0;
}

std::ostream& operator<<(std::ostream& os, Rational f) // << (f1+f2)
//第一个是流的对象，第二个是传入到流里面的数据
//返回类型是ostream流的引用，在调用重载函数时operator<<()重载函数时传递给他时那个流
//它返回的就是那个流的一个参数，也就是流的引用
{
    os << f.numerator << "/" << f.denominator;
    //以这样的形式把f1,f2打印出来 
    return os;
}

