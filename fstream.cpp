#include <fstream>//读
#include <iostream>
using namespace std;
int main ()
{
ifstream in;//ipu file stream 文件输入流的一个类，定义in一个对象
//<fstream>库允许编程人员利用ifstream和ofstream类进行文件输入和输出. 
in.open("biann.txt");
if (!in)
{
    cout<<"dont"<<endl;
    return 0 ;
}
char x;//定义变量是一个良好的习惯
while ( in >> x )
{
    cout<<x;
}
cout<<endl ;
in.close( ) ;
}