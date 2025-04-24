/* 
//this cpp
int i1=1;
//that cpp
int i2=i1//这样是错的，因为两个文件没有链接在一起


//this  cpp
extern int i1;//链接在一起
//that cpp
int  i2=i1;

//this cpp
static int i1=9;//i1是局部变量
//that cpp
static int i1=5;//static定义静态变量，是一个内连接
//只在文件的内部才能使用
 */
