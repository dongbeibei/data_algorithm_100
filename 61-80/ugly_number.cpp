/*

*/

#include <iostream>   
using namespace std;   
  
int mymin(int a, int b, int c)   
{   
    int temp = (a < b ? a : b);   
    return (temp < c ? temp : c);   
}   
int FindUgly(int n)
{   
    int* ugly = new int[n];   
    ugly[0] = 1;   
    int index2 = 0;   
    int index3 = 0;   
    int index5 = 0;   
    int index = 1;   
    while (index < n)   
    {   
        int val = mymin(ugly[index2]*2, ugly[index3]*3, ugly[index5]*5);  
        if (val == ugly[index2]*2) 
            ++index2;   
        if (val == ugly[index3]*3)
			++index3;   
        if (val == ugly[index5]*5)   
            ++index5;   
        ugly[index++] = val;   
    }   
 /*/
    for (int i = 0; i < n; ++i)   
        cout << ugly[i] << endl;   
 /*/
    int result = ugly[n-1];   
    delete[] ugly;   
    return result;   
}   
 
int main()   
{   
    int num=1;
    cout<<"input the number: \n";
    cin>>num;
    cout<<FindUgly(num)<<endl;   
    return 0;   
}
