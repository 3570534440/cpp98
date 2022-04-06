#include <iostream>
#include <conio.h>
#include<stdio.h>

using namespace std;
#define TRUE 1
#define FALSE 0
#define Maxsize 200  //���е����ռ�
typedef unsigned long int LINT;//LINKΪ�޷���long int

typedef struct//����һ������
{
	LINT data[Maxsize]; //���е����ݴ�СΪ200��
	int front,rear;	//���е�ͷָ���βָ��
}Sequeue;

Sequeue *Sq,mysqueue;//�������mysqueue,��ָ����е�ָ��*Sq
void Set_queue_Null(Sequeue *sq); //���в�������
int Empty_queue(Sequeue *sq); //�ж϶����Ƿ�Ϊ��
int In_queue(Sequeue *sq,LINT x); //����Ϊ*Sq��x
LINT Out_queue(Sequeue *sq);//�����еĺ��� 
void Clear_screen(); //��������

int main()//������
{
LINT n,i,j,temp1,temp2;

Sq=&mysqueue;//SqΪSequeue *Sq
Next: 
Set_queue_Null(Sq);
printf("������������ǵĽ���:n=");
scanf("%d",&n);
In_queue(Sq,1);// ��1�������
printf("\n");

for(i=1;i<=n;i++)//��������Ǵ�ӡ����
{
	temp2=0;
	for(j=1;j<i;j++)
	{
	temp1=Out_queue(Sq);//�õ����е�Ԫ��
	printf("%-5lu",temp1);//��ӡ�õ���Ԫ��
	temp2+=temp1;
	In_queue(Sq,temp2);//��temp���
	temp2=temp1;
	}
Out_queue(Sq);
printf("1\n");//��ӡ1
temp2++;
In_queue(Sq,temp2);//��temp���

In_queue(Sq,1);
}
	Clear_screen();//ѯ���Ƿ�����
	printf("���Ƿ�Ҫ��������\n Y(��) or N(��)?\n");
	char response;
	scanf("%c",&response);
	if(response=='Y'||response=='y')
	goto Next;
	else
	{
	printf("�������...\n");
	}

}

void Set_queue_Null(Sequeue *sq)//�����е�ͷβָ��ָ�����������
{
sq->front=Maxsize-1;
sq->rear=Maxsize-1;
}

int Empty_queue(Sequeue *sq)//�ж϶����Ƿ�Ϊ��
{
if(sq->rear==sq->front)
return TRUE;//����ǿյĻ�������1
else
return FALSE;
}

int In_queue(Sequeue *sq,LINT x)
{
	if(sq->front==(sq->rear+1)%Maxsize)//�ж϶����Ƿ�����
	{
	printf("��������!\n");
	return FALSE;
	}
	else
	{
	sq->rear=(sq->rear+1)%Maxsize;//����еĲ���
	sq->data[sq->rear]=x;//�����
	return TRUE;
	}
}

LINT Out_queue(Sequeue *sq)//�����еĺ���
{
	if(Empty_queue(sq))//�ж϶����Ƿ�Ϊ��
	{
	printf("�����ǿյ�!\n");
	return FALSE;//��Ϊ�գ�����0
	}
	else
	{
	sq->front=(sq->front+1)%Maxsize;//ͷָ���һ
	return (sq->data[sq->front]);//���ش�ʱͷָ��ָ�������
	}
}

void Clear_screen()//ѯ���Ƿ�����
{
printf("�Ƿ������Ļ��(Y/N)\n");
if(getche()=='y'||getche()=='Y')
return;
else
printf("��������...\n");
}
