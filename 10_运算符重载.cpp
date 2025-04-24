//MyTime.h文件：
#pragma once
#ifndef MYTIME_H_
#define MYTIME_H_
class CMyTime
{
      private:
      int m_hours;
      int m_minutes;
      public:
      CMyTime();
      CMyTime(int h, int m = 0);
      void AddHr(int h);  //小时更改
      void AddMin(int m);//分钟更改
      void Reset(int h = 0, int m = 0);  //重新设置时间
      CMyTime operator+(const CMyTime &t) const;  //重载加法
      CMyTime operator-(const CMyTime &t) const;  //重载减法
      CMyTime operator*(double n) const;          //重载乘法//返回类型 operator 运算符（参数）
      //包含被重载的运算符的表达式会被编译成对运算符函数的调用，
      //运算符的操作数成为函数调用时的实参，运算的结果就是函数的返回值。运算符可以被多次重载。
      void Show() const;
      ~CMyTime();
};
#endif


//MyTIme.cpp文件：
#include "stdafx.h"
#include "MyTime.h"
#include <iostream>
 
CMyTime::CMyTime()
{
   m_hours = 0;
   m_minutes = 0;
}
 
 
CMyTime::CMyTime(int h, int m)
{
   m_hours = h;
   m_minutes = m;
}
 
 
CMyTime::~CMyTime()
{
}
 
 
void CMyTime::AddHr(int h)                                             //小时更改
{
   m_hours += h;
}
 
 
void CMyTime::AddMin(int m)                                             //分钟更改
{
   m_minutes = m;
}
 
 
void CMyTime::Reset(int h, int m)                                           //重新设置时间
{
   m_hours = h;
   m_minutes = m;
}
 
 
CMyTime CMyTime::operator+(const CMyTime &t) const              //重载加法运算符函数
{
   CMyTime sum;
   sum.m_minutes = t.m_minutes + m_minutes;
   sum.m_hours = t.m_hours+ m_hours + sum.m_minutes / 60;
   sum.m_minutes %= 60;
   return sum;
}
 
 
CMyTime CMyTime::operator-(const CMyTime &t) const         //重载为减法运算符函数
{
   CMyTime diff;
   int tot1, tot2;
   tot1 = t.m_minutes + 60 * t.m_hours;
   tot2  = m_minutes + 60 * t.m_hours;
   diff.m_minutes = (tot2 - tot1) % 60;
   diff.m_hours = (tot2 - tot1) / 60;
   return diff;
}
 
 
CMyTime CMyTime::operator*(double n) const                 //重载为乘法运算符函数。
{
   CMyTime result;
   long totalMinutes = m_hours * 60 * n+ m_minutes *n;
   result.m_minutes = totalMinutes % 60;
   result.m_hours = totalMinutes / 60;
   return result;
}
 
 
void CMyTime::Show() const
{
   std::cout << m_hours << " hours "
   << m_minutes << " minutes\n";
}
// Study11-02.cpp : 定义控制台应用程序的入口点。
//
 
#include "stdafx.h"
#include <iostream>
#include "MyTime.h"
 
 
int _tmain(int argc, _TCHAR* argv[])
{
   using std::cout;
   using std::endl;
   CMyTime weeding(4, 35);
   CMyTime waxing(2, 47);
   CMyTime total;
   CMyTime diff;
   CMyTime adjusted;
   
   
   cout << "weeding Time = ";
   weeding.Show();
   cout << endl;
   
   
   cout << "waxing Time = ";
   waxing.Show();
   cout << endl;
   
   
   cout << "total work Time = ";   //（1）
   total = weeding + waxing;
   total.Show();
   cout << endl;
   
   
   diff = weeding - waxing;
   cout << "weeding Time - waxing Time = "; //（2）
   diff.Show();
   cout << endl;
   
   
   adjusted = total *1.5;                     //（3）
   cout << "adjusted work Time = ";
   adjusted.Show();
   cout << endl;
   return 0;
}