/*
 * ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ�
 * ��˳�򲻱䡣�����е����Կո��������Ϊ������������ź�
 * ��ͨ��ĸһ������
 * �������롰I am a student.�����������student. a am I����
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
