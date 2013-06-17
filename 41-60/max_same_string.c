/*
最长公共字串。
题目：如果字符串一的所有字符按其在字符串中的顺序出现在另外
一个字符串二中，则字符串一称之为字符串二的子串。
注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。

请编写一个函数，输入两个字符串，求它们的最长公共子串，
并打印出最长公共子串。

例如：输入两个字符串BDCABA 和ABCBDAB，字符串BCBA 和BDAB 都是它们
的最长公共子串，则输出它们的长度4，并打印任意一个子串。

分析：求最长公共子串（Longest Common Subsequence, LCS）是一道非常经典的
动态规划题，因此一些重视算法的公司像MicroStrategy 都把它当作面试题。

 *
 */

#define  MaxSize 200   
#include <stdio.h>   
#include <string.h>   
char p[MaxSize+10];  
char q[MaxSize+10];  
int MaxComLen[MaxSize+10][MaxSize+10];  //MaxComLen[i][j]表示以第一个串第i个元素，第二个串第j个元素为终点的最大公共子串   
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
            MaxComLen[0][j]=0;           //如果i或者j为0，最长公共字串为0   
        for(i=1;i<=plen;i++)  
        {  
            for (j=1;j<=qlen;j++)  
            {  
                if (p[i]==q[j])  
                    MaxComLen[i][j]=MaxComLen[i-1][j-1]+1;//如果p[i]=q[j],MaxComLen[i][j]=MaxComLen[i-1][j-1]+1   
                else  
                {  
                    if(MaxComLen[i-1][j]>MaxComLen[i][j-1])//如果p[i]!=q[j],MaxComLen[i][j]=MAX(MaxComLen[i][j-1],MaxComLen[i-1][j])   
                        MaxComLen[i][j]=MaxComLen[i-1][j];  
                    else  
                        MaxComLen[i][j]=MaxComLen[i][j-1];  
                }  
                if (MaxComLen[i][j]>maxlen)          //输出最大的长度，按照定义应该为最后一个元素   
                    maxlen=MaxComLen[i][j];  
            }  
        }  
        printf("%d\n",maxlen);  
    }  
    return 0;  
}  

