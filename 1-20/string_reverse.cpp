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

//void my_swap(char *start, char *end);
char *reverse(char *str);

int main(void)
{
	const char *first = "I am a student.";
	char *test, *result;

	test = const_cast<char *>(first);
	result = reverse(test);

//	cout<<"result:\n\t"<<result<<endl;

	return 0;
}
/*
void my_swap(char *a, char *b)
{
	char temp;
	cout<<"a:"<<*a<<endl;
	cout<<"b:"<<*b<<endl;
	temp = *a;
	cout<<"temp:"<<temp<<endl;
	*a++ = *b;
	*b-- = temp;

	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
}
*/
char *reverse(char *str)
{
	char	*start, *end, *temp;
	char	ch;

	end = start = str;
	while(*end != '\0')
		end++;
	end -= 1;
	while(start < end)
	{
		ch = *start;
		*start++ = *end;
		*end-- = ch;
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
				ch = *start;
				*start++ = *end;
				*end-- = ch;
			}

			start = end = temp+1;
		}

		end++;
	}

	end -= 1;
	while(start < end)
	{
		ch = *start;
		*start++ = *end;
		*end-- = ch;
	}

	return str;
}
