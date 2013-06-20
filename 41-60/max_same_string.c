/*
������ִ���
��Ŀ������ַ���һ�������ַ��������ַ����е�˳�����������
һ���ַ������У����ַ���һ��֮Ϊ�ַ��������Ӵ���
ע�⣬����Ҫ���Ӵ����ַ���һ�����ַ����������������ַ������С�

���дһ�����������������ַ����������ǵ�������Ӵ���
����ӡ��������Ӵ���

���磺���������ַ���BDCABA ��ABCBDAB���ַ���BCBA ��BDAB ��������
��������Ӵ�����������ǵĳ���4������ӡ����һ���Ӵ���

��������������Ӵ���Longest Common Subsequence, LCS����һ���ǳ������
��̬�滮�⣬���һЩ�����㷨�Ĺ�˾��MicroStrategy ���������������⡣

 *
 */

#define  MaxSize 200   
#include <stdio.h>   
#include <string.h>   
char p[MaxSize+10];  
char q[MaxSize+10];  
int MaxComLen[MaxSize+10][MaxSize+10];  //MaxComLen[i][j]��ʾ�Ե�һ������i��Ԫ�أ��ڶ�������j��Ԫ��Ϊ�յ����󹫹��Ӵ�   
int main()  
{  
    int i,j,max;  
    int plen=0,qlen=0;  
    while(scanf("%s%s",p+1,q+1)>0)  
    {  
        int maxlen=0;  
        plen=strlen(p+1);  
        qlen=strlen(q+1);  
        for (i=0;i<=plen;i++)  
            MaxComLen[i][0]=0;  
        for (j=0;j<=qlen;j++)  
            MaxComLen[0][j]=0;           //���i����jΪ0��������ִ�Ϊ0   
        for(i=1;i<=plen;i++)  
        {  
            for (j=1;j<=qlen;j++)  
            {  
                if (p[i]==q[j])  
                    MaxComLen[i][j]=MaxComLen[i-1][j-1]+1;//���p[i]=q[j],MaxComLen[i][j]=MaxComLen[i-1][j-1]+1   
                else  
                {  
                    if(MaxComLen[i-1][j]>MaxComLen[i][j-1])//���p[i]!=q[j],MaxComLen[i][j]=MAX(MaxComLen[i][j-1],MaxComLen[i-1][j])   
                        MaxComLen[i][j]=MaxComLen[i-1][j];  
                    else  
                        MaxComLen[i][j]=MaxComLen[i][j-1];  
                }  
                if (MaxComLen[i][j]>maxlen)          //������ĳ��ȣ����ն���Ӧ��Ϊ���һ��Ԫ��   
                    maxlen=MaxComLen[i][j];  
            }  
        }  
        printf("%d\n",maxlen);  
    }  
    return 0;  
}  

