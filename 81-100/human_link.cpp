/*
多人排成一个队列,我们认为从低到高是正确的序列,但是总有部分人
不遵守秩序。如果说,前面的人比后面的人高(两人身高一样认为是
合适的), 那么我们就认为这两个人是一对"捣乱分子",
比如说,现在存在一个序列:
176, 178, 180, 170, 171
这些捣乱分子对为
<176, 170>, <176, 171>, <178, 170>, <178, 171>, <180, 170>, <180, 171>,
那么,现在给出一个整型序列,请找出这些捣乱分子对的个数
(仅给出捣乱分子对的数目即可,不用具体的对)

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

