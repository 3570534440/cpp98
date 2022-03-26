#include<fstream>
#include<iostream>

using namespace std;

int main ()
{
    fstream fp("biann.txt",ios::in|ios::out);
    //ios::in打开一个可读取文件
    // ios::out打开一个可写入文件
    // ios::binary以二进制形式打开一个文件
    // ios::app写入的所有数据将被追加到文件的末尾
    // ios::trunk删除文件原来已经存在的内容
    //打开文件并写进 去，
    if (!fp)
    {
        cout<<"dont"<<endl;
        return 0;
    }
    fp<<"asfhfgasscasfsdas";
    static char str[10];
    //定义不能被改变的静态数组
    fp.seekg(ios::end);
    //使得文件指针指向文件头。ios::end是指向文件未
    fp>>str;
    cout<<str<<endl;

    fp.close();
    return 0;

}