#include<fstream>//文件流file stream
#include<iostream>

using namespace std;
int main ()
{
ofstream out;
out.open("biann.txt");
if(!out)
{
    cout<<"dont"<<endl;
    return 0;
}
int i;
for(i=0;i<10;i++)//写1-10
{
    out<<i;
}//EOF：文件的结尾 
cout<<endl;
out.close();
}