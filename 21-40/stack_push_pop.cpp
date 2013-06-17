/*
题目：输入两个整数序列。其中一个序列表示栈的push 顺序，
判断另一个序列有没有可能是对应的pop 顺序。
为了简单起见，我们假设push 序列的任意两个整数都是不相等的。
比如输入的push 序列是1、2、3、4、5，
那么4、5、3、2、1 就有可能是一个pop 系列。
因为可以有如下的push 和pop 序列：
push 1，push 2，push 3，push 4，pop，push 5，pop，pop，pop，pop，
这样得到的pop 序列就是4、5、3、2、1。
但序列4、3、5、1、2 就不可能是push 序列1、2、3、4、5 的pop 序列。
 *
 * author:	dongbeibei
 * time:		2013/6/13
 */


#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int input[] = {1,2,3,4,5};
	int output[] = {1,2,3,4,5};
	int len_in, len_out, i, j;
	stack<int>	test;
	bool flag;

	flag = true;
	len_in = sizeof(input)/sizeof(int);
	len_out = sizeof(output)/sizeof(int);

	for(i=0,j=0 ; j<len_out ; j++)
	{
		while(test.empty())
			test.push(input[i++]);

		while(test.top() != output[j])
			if(i < len_in)
				test.push(input[i++]);
			else
			{
				flag = false;
				break;
			}

		test.pop();
	}

	if(flag)
		cout<<"the output[] can be the right order"<<endl;
	else
		cout<<"the bad order"<<endl;

	return 0;
}
