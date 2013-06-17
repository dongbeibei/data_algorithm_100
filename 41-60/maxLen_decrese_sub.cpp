/*
求一个数组的最长递减子序列比如{9，4，3，2，5，4，3，2}
的最长递减子序列为{9，5，4，3，2}
 *
 * author:	dongbeibei
 * time:		2013/6/19
 */


#include <iostream>
using namespace std;

int BiSearch(int *A,int nTarget,int nLen);  
void FindLongestSequence(int *A,int nLen)  
{  
    int *index=new int[nLen];  
    int *LDS=new int[nLen];  
    index[0]=A[0];  
    LDS[0]=1;  
    int indexLen=1, i;  
    for (i=1;i<nLen;i++)  
    {  
        int pos=BiSearch(index,A[i],indexLen);  
        index[pos]=A[i];  
        LDS[i]=pos+1;  
        if(pos>=indexLen)  
            indexLen++;  
    }  
    int ResultLen=indexLen;  
    for (i=nLen;i>=0;i--)  
    {  
        if(LDS[i]==ResultLen)  
        {     
            index[ResultLen-1]=A[i];  
            ResultLen--;  
        }         
    }  
  
    for (i=0;i<indexLen;i++)  
    {  
        cout<<index[i]<<" ";  
    }
	cout<<endl;
    delete []index;  
  
}  
int BiSearch(int *A,int nTarget,int nLen)  
{  
    //assert(A!=NULL&&nLen>0);  
    int start=0;  
    int end=nLen-1;  
    while (start<=end)  
    {  
        int mid=(start+end)/2;  
        if(nTarget>A[mid])  
            end=mid-1;  
        else if(nTarget<A[mid])  
            start=mid+1;  
        else  
            return mid;  
    }  
    return start;  
}  

int main(void)
{
	int A[] = {9, 4, 3, 2, 5, 4, 3, 2};
	int nLen=sizeof(A)/sizeof(int);  
    FindLongestSequence(A,nLen);  

	return 0;
}
