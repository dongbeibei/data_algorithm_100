/*
дһ������,����ԭ����int continumax(char *outputstr,char *intputstr)
���ܣ�
���ַ������ҳ�����������ִ�������������ĳ��ȷ��أ�
�����������ִ���������һ����������outputstr ��ָ�ڴ档
���磺"abcd12345ed125ss123456789"���׵�ַ����intputstr �󣬺���������9��
outputstr ��ָ��ֵΪ123456789
 *
 * author:	dongbeibei
 * time:		2013/6/12
 */


#include <iostream>

using namespace std;

int continumax(char *outputstr, char *inputstr);

int main(void)
{
	const char *test = "abcd12345ed125ss123456789";
	char result[100];
	int	number;

	number = continumax(result, const_cast<char *>(test));

	cout<<"number:\t"<<number<<endl;
	cout<<"result:\t"<<result<<endl;

	return 0;
}

int continumax(char *outputstr, char *inputstr)
{
	char	*pre, *start, *cur;
	int		pre_sum, cur_sum, flag;

	cur = inputstr;
	pre_sum = cur_sum = 0;
	flag = 0;

	while(*cur++ != '\0')
	{
		if(*cur>='0' && *cur<='9')
		{
			if(cur_sum == 0)
			{
				flag = 1;
				start = cur;
			}

			cur_sum++;
		}
		else
		{
			if(flag == 1)
			{
				if(pre_sum < cur_sum)
				{
					pre_sum = cur_sum;
					pre = start;
				}

				flag = 0;
				cur_sum = 0;
			}
		}
	
		//cur++;
	}

	for(int i=0 ; i<pre_sum ; i++)
	{
		*(outputstr+i) = *(pre+i);
	}
	*(outputstr+pre_sum) = '\0';
	outputstr = pre;
	
	return pre_sum;
}

/*
int continumax(char *outputstr, char *inputstr) {
  int len = 0;
  char * pstart = NULL;
  int max = 0;
  while (1) {
    if (*inputstr >= '0' && *inputstr <='9') {
      len ++;
    } else {
      if (len > max) pstart = inputstr-len;
      len = 0;
    }
    if (*inputstr++=='\0') break;
  }
  for (int i=0; i<len; i++)
    *outputstr++ = pstart++;
  *outputstr = '\0';
  return max;
}
*/
