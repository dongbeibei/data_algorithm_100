/*
两个小数相乘，小数点后没有位数的限制，写出一个高精度的算法
 *
 * author:	dongbeibei
 * time:		2013/7/2
 */


#include <iostream>
#include <string.h>
 using namespace std;
#define MAX 10000
 struct Node{
 int data;
 Node *next;
 };
 void output(Node *head,int pos)
 {
 if(!head->next&&!head->data)return;
 output(head->next,pos-1);
 cout<<head->data;
 if(!pos)cout<<".";
 }
 void Mul(char *a,char *b,int pos)		   
 {
 char *ap=a,*bp=b;
 Node *head=0;
 head=new Node;head->data=0,head->next=0;	 //头
 Node *p,*q=head,*p1;
 int temp=0,temp1,bbit;
 while(*bp) 				//若乘数不为空 ,继续.
 {
 p=q->next;p1=q;
 bbit=*bp-48;			//把当前位转为整型
 while(*ap||temp)			  //若被乘数不空,继续
 {
 if(!p) 			//若要操作的结点为空,申请之
 {
 p=new Node;
 p->data=0;
 p->next=0;
 p1->next=p;
 }
 if(*ap==0)temp1=temp;
 else { temp1=(p1->data)+(*ap-48)*bbit+temp;ap++; }
 p1->data=temp1;	 //留当前位
 temp=temp1/10; 	//进位以int的形式留下.
 p1=p;p=p->next;				  //被乘数到下一位
 }
 ap=a;bp++;q=q->next;				  //q进下一位
 }
 p=head;
 output(p,pos); 				   //显示
 cout<<endl;
 while(head)				  //释放空间
 {
 p=head->next;
 delete head;
 head=p;
 }
 }
 int main()
 {
 cout<<"请输入两个数"<<endl;
 char test1[MAX],test2[MAX],*p;
 int pos=0;
 cin.getline(test1,MAX,'\n');
 cin.getline(test2,MAX,'\n');
 if(p=strchr(test1,'.'))
 {
 pos+=strlen(test1)-(p-test1)-1;
 do
 {
 p++;
 *(p-1)=*p;
 }while(*p);
 }		  
 if(p=strchr(test2,'.'))
 {
 pos+=strlen(test2)-(p-test2)-1;
 do
 {
 p++;
 *(p-1)=*p;
 }while(*p);
 }	 
// Mul(strrev(test1),strrev(test2),pos); 
 Mul(test1,test2,pos);
 //system("PAUSE");
 return 0;
 }

