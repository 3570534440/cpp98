#include <iostream>
#include <climits>
class Factroal
{
public:
    Factroal(unsigned short num);
    unsigned long getFactroal();
    bool inRange();//检测的函数，是否在范围内

    private:
    unsigned short num;
};
Factroal::Factroal(unsigned short num)
{
    this->num=num;
}
unsigned long Factroal::getFactroal()
{
    unsigned long sum =1;
    for(int i=1;i<=num;i++)
    {
        sum*=i;
    }
    return sum;
}
bool Factroal:: inRange()//纠正
{
    unsigned long max=ULONG_MAX;
    //提前获取这个值的最大值然后返回
    //比如SHORT_MIN表示最小值SHORT_MAX表示这个类型的最大值
    //ULONG_MAX表示无符号长整形的最大值
    for(int i=num;i>=1;--i)
    {
            max=max/i;
    }
    if(max<1)
    {  
        return false;
    }
    else
    {
        return true;
    }
    
}
int main()       
{
    unsigned short num=0; 
    std::cout<<"plice in put score\n\n";
    std::cin>>num;
    Factroal fac(num);
    if(fac.inRange())
    {
        std::cout<<num<<"is"<<fac.getFactroal()<<"\n\n";
    }
    else
    {
        std::cout<<"big.big\n\n";
    }
    return 0;
}