/*
����С����ˣ�С�����û��λ�������ƣ�д��һ���߾��ȵ��㷨
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
 head=new Node;head->data=0,head->next=0;	 //ͷ
 Node *p,*q=head,*p1;
 int temp=0,temp1,bbit;
 while(*bp) 				//��������Ϊ�� ,����.
 {
 p=q->next;p1=q;
 bbit=*bp-48;			//�ѵ�ǰλתΪ����
 while(*ap||temp)			  //������������,����
 {
 if(!p) 			//��Ҫ�����Ľ��Ϊ��,����֮
 {
 p=new Node;
 p->data=0;
 p->next=0;
 p1->next=p;
 }
 if(*ap==0)temp1=temp;
 else { temp1=(p1->data)+(*ap-48)*bbit+temp;ap++; }
 p1->data=temp1;	 //����ǰλ
 temp=temp1/10; 	//��λ��int����ʽ����.
 p1=p;p=p->next;				  //����������һλ
 }
 ap=a;bp++;q=q->next;				  //q����һλ
 }
 p=head;
 output(p,pos); 				   //��ʾ
 cout<<endl;
 while(head)				  //�ͷſռ�
 {
 p=head->next;
 delete head;
 head=p;
 }
 }
 int main()
 {
 cout<<"������������"<<endl;
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

