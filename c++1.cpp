#include <iostream>
using namespace std;
int main()
{
    int i,sum;
    sum=0;
    cout<<"请输入数字和空格\n\n\n:";
while(cin>>i)
{
    sum=sum+1;
    while (cin.peek()==' ')//peek是查找下一个字符
    {
        cin.get();
    }
    if (cin.peek()=='\n');
    {
        break;
    }
}
std::cin.ignore(100,'\n');//忽略回车
     cout<<"结果是"<< sum<<endl;
     cin.get();//暂停
 return 0;
}