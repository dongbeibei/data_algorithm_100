#include<iostream>   
#include<cassert>   
#include <vector>   
using namespace std ; 

int i=0;
 
void Print(vector<char> v)  
{  
	i++;
    for (vector<char>::iterator beg=v.begin();beg!=v.end();++beg)  
        cout<<*beg<<" ";  
    cout<<endl;  
}  
void MatchNums(int nSize,int nLen,vector<char> &v)  
{  
    int nLeftBrackets=0;  
    int nRightBrackets=0;  
    for (vector<char>::iterator beg=v.begin();beg!=v.end();++beg)  
    {  
        if(*beg=='(')  
            nLeftBrackets++;  
        else  
            nRightBrackets++;  
        if(nRightBrackets>nLeftBrackets)  
            return;  
        if(nLeftBrackets+nRightBrackets==nSize&&nLeftBrackets==nRightBrackets)  
            Print(v);  
    }  
      
    if (nLen>0)  
    {  
        v.push_back('(');  
        MatchNums(nSize,nLen-1,v);  
        v.pop_back();  
        v.push_back(')');  
        MatchNums(nSize,nLen-1,v);  
        v.pop_back();  
    }  
}  
int main()  
{  
    vector <char> v;  
    int n;
	cin>>n;  
    MatchNums(n,n,v);  
	cout<<i<<endl;
    return 1;  
}
