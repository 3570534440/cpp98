#include<fstream>
#include<iostream>

using namespace std;

int main ()
{
    ofstream out;
    out.open("biann.txt",ios::app);
    if(!out)
    {
        cout<<"dont"<<endl;
        return 0;
    }
    for( int i=10;i>0;i--)

    {
        out<<i;//Ð´Èë
    }
    out<<endl;
    out.close();

    return 0;

}