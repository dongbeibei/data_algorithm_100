/*
�����ų�һ������,������Ϊ�ӵ͵�������ȷ������,�������в�����
�������������˵,ǰ����˱Ⱥ�����˸�(�������һ����Ϊ��
���ʵ�), ��ô���Ǿ���Ϊ����������һ��"���ҷ���",
����˵,���ڴ���һ������:
176, 178, 180, 170, 171
��Щ���ҷ��Ӷ�Ϊ
<176, 170>, <176, 171>, <178, 170>, <178, 171>, <180, 170>, <180, 171>,
��ô,���ڸ���һ����������,���ҳ���Щ���ҷ��ӶԵĸ���
(���������ҷ��ӶԵ���Ŀ����,���þ���Ķ�)

*/

#include<iostream>   
using namespace std;  
  
int CalcAndMerge(int arr[],int left,int mid,int right);  
int FindTrouble(int arr[],int left,int right);  
  
int FindTrouble(int arr[],int left,int right)  
{  
    if(left>=right)    
        return 0;  
    int mid = left+(right-left)/2;  
    return FindTrouble(arr,left,mid)+FindTrouble(arr,mid+1,right)+CalcAndMerge(arr,left,mid,right);  
}  
int CalcAndMerge(int arr[],int left,int mid,int right)  
{  
    int left1=left,right1=mid,left2=mid+1,right2=right;  
    if(left1>right1 || left2>right2)  
        return 0;  
    int i=left1,j=left2;  
    int sum=0;  
    while(i<=right1 && j<=right2)  
    {  
        while(i<=right1 && arr[i]<=arr[j])  
            i++;  
        if(i<=right1)  
        {  
            sum+=right1-i+1;  
            j++;  
        }  
    }  
    //merge   
    i=left1;j=left2;  
    int *tmp=new int[right-left+1];  
    int t=0;  
    while(i<=right1 && j<=right2)  
    {  
        if(arr[i]<arr[j])  
            tmp[t++]=arr[i++];  
        else  
            tmp[t++]=arr[j++];  
    }  
    while(i<=right1)  
            tmp[t++]=arr[i++];  
    while(j<=right2)  
            tmp[t++]=arr[j++];  
    for(t=0,i=left;i<=right;t++,i++)  
        arr[i]=tmp[t];  
    return sum;  
}  
  
int main()  
{  
    int arr[]={5,3,7,5,1,12,9,7,2,9,9,4,1,7,3,6,10,6};  
    int output = FindTrouble(arr,0,sizeof(arr)/sizeof(int)-1);  
    cout<<output<<endl;  
    return 0;  
}  

