#include<iostream>

int main ()
{
    const unsigned short ADD_SUBTRACT=32;
    const double RATIO=9.0/5.0;
    double a,b;//a是摄氏，b是华氏
    char c,d;//同上

    std::cout<<"XX.X C  or  XX.X F"<<std::endl;
    std::cin>>a>>c;
    std::cin.ignore(100,'\n');
    std::cout<<"\n";
    
    switch (c)

    {
    case 'c':
    case 'C':
    b =a*RATIO+ADD_SUBTRACT;
    c='c';
    break;
    
    case 'f':
    case 'F':
    a=(b-ADD_SUBTRACT)/RATIO;
    d='f';
    break;
    default:
    c='e';
    break;
    }
    std::cout<<a<<c<<"="<<b<<d<<"\n\n";
    std::cin.get();
    return 0;
}