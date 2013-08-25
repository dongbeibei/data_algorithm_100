/*
 * 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符
 * 的顺序不变。句子中单词以空格符隔开。为简单起见，标点符号和
 * 普通字母一样处理。
 * 例如输入“I am a student.”，则输出“student. a am I”。
 *
 * author:		dongbeibei
 * building time:	2013/6/11
 */


#include <iostream>

using namespace std;

void my_swap(char &a, char &b);
void reverse(char *str);

int main(void)
{
	char test[] = "I am a student.";

	reverse(test);

	cout<<"result:\n\t"<<test<<endl;

	return 0;
}

void my_swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void reverse(char *str)
{
	char	*start, *end, *temp;
	char	ch;

	end = start = str;
	while(*end != '\0')
		end++;
	end -= 1;
	while(start < end)
	{
		my_swap(*start, *end);
		start++;
		end--;
	}

	end = start = str;
	while(*end != '\0')
	{
		if(*end == ' ')
		{
			temp = end;
			end -= 1;
			while(start < end)
			{
				my_swap(*start, *end);
				start++;
				end--;
			}

			start = end = temp+1;
		}

		end++;
	}
/*
	end -= 1;
	while(start < end)
	{
		swap(start, end);
		start++;
		end--;
	}
*/
}
