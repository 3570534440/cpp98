#include <iostream>
#include <conio.h>
#include<stdio.h>

using namespace std;
#define TRUE 1
#define FALSE 0
#define Maxsize 200  //队列的最大空间
typedef unsigned long int LINT;//LINK为无符号long int

typedef struct//定义一个队列
{
	LINT data[Maxsize]; //队列的数据大小为200，
	int front,rear;	//队列的头指针和尾指针
}Sequeue;

Sequeue *Sq,mysqueue;//定义队列mysqueue,和指向对列的指针*Sq
void Set_queue_Null(Sequeue *sq); //对列操作函数
int Empty_queue(Sequeue *sq); //判断队列是否为空
int In_queue(Sequeue *sq,LINT x); //参数为*Sq和x
LINT Out_queue(Sequeue *sq);//出队列的函数 
void Clear_screen(); //清屏函数

int main()//主函数
{
LINT n,i,j,temp1,temp2;

Sq=&mysqueue;//Sq为Sequeue *Sq
Next: 
Set_queue_Null(Sq);
printf("请输入杨辉三角的阶数:n=");
scanf("%d",&n);
In_queue(Sq,1);// 将1进入队列
printf("\n");

for(i=1;i<=n;i++)//将杨辉三角打印出来
{
	temp2=0;
	for(j=1;j<i;j++)
	{
	temp1=Out_queue(Sq);//得到队列的元素
	printf("%-5lu",temp1);//打印得到的元素
	temp2+=temp1;
	In_queue(Sq,temp2);//将temp入队
	temp2=temp1;
	}
Out_queue(Sq);
printf("1\n");//打印1
temp2++;
In_queue(Sq,temp2);//将temp入队

In_queue(Sq,1);
}
	Clear_screen();//询问是否清屏
	printf("你是否还要继续进行\n Y(是) or N(否)?\n");
	char response;
	scanf("%c",&response);
	if(response=='Y'||response=='y')
	goto Next;
	else
	{
	printf("程序结束...\n");
	}

}

void Set_queue_Null(Sequeue *sq)//将队列的头尾指针指向最后数据域
{
sq->front=Maxsize-1;
sq->rear=Maxsize-1;
}

int Empty_queue(Sequeue *sq)//判断队列是否为空
{
if(sq->rear==sq->front)
return TRUE;//如果是空的话，返回1
else
return FALSE;
}

int In_queue(Sequeue *sq,LINT x)
{
	if(sq->front==(sq->rear+1)%Maxsize)//判断队列是否已满
	{
	printf("队列已满!\n");
	return FALSE;
	}
	else
	{
	sq->rear=(sq->rear+1)%Maxsize;//入队列的操作
	sq->data[sq->rear]=x;//入队列
	return TRUE;
	}
}

LINT Out_queue(Sequeue *sq)//出队列的函数
{
	if(Empty_queue(sq))//判断队列是否为空
	{
	printf("队列是空的!\n");
	return FALSE;//若为空，返回0
	}
	else
	{
	sq->front=(sq->front+1)%Maxsize;//头指针加一
	return (sq->data[sq->front]);//返回此时头指针指向的数据
	}
}

void Clear_screen()//询问是否清屏
{
printf("是否清除屏幕？(Y/N)\n");
if(getche()=='y'||getche()=='Y')
return;
else
printf("继续操作...\n");
}
