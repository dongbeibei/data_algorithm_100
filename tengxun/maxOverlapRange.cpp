/*
��Ŀ���������д�����ҳ����桰�������ݼ���ʽ������������
���������ļ�������ص�����Ĵ�С��

��һ��������n�����n�������ļ���ĳ�е�����������������ΪA��B��
֮�䣬��A<=n<=B��A>=n>=B����n���ڸ��У����nͬʱ������i��j����i��j��
�ص����䣻�ص�����Ĵ�С��ͬʱ������i��j������������

���磬�У�10 20���ͣ�12 25�����ص�����Ϊ[12 20]�����СΪ9��
�У�20 10���ͣ�12 18�����ص�����Ϊ[10 12]�����СΪ3��
��(20 10)�ͣ�20 30�����ص������СΪ1��

�������ݣ���������ѱ�����Ϊinput.txt�����������ı��ļ������ļ���
������1��1,000,000֮�䣬ÿ������һ���ո�ָ���2����������
��2���������Ĵ�С���������ÿ��������1��2^32-1֮�䡣
��Ϊ���ڵ��ԣ��������ز���input.txt�ļ���ʵ������ʱ���ǻ�ʹ��
��ͬ���ݵ������ļ�����

������ݣ��ڱ�׼����ϴ�ӡ�����������ļ�������ص�����Ĵ�С��
��������ж�û���ص����䣬�����0��

���ֱ�׼������������������ȷ���ڴ�ʹ�ñ��벻����256MB��
�����ִ��ʱ��Խ��Խ�á�


 * author:	dongbeibei
 * time:		2013/7/4
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int>b);

int main(void)
{
	int		a, b, x, i, m, n, temp;
	vector<pair<int,int> > interval;
	ifstream in("input.txt");
	while(in>>a>>b)
	{
		if(a<b)
			interval.push_back(make_pair(a,b));
		else
			interval.push_back(make_pair(b,a));
	}
	in.close();

	sort(interval.begin(), interval.end(), cmp);
	int maxcover = 0;
	int end = interval[0].second;
	int right, cover;

	m = n = 0;
	temp = 0;
	for(i=1 ; i<interval.size() ; i++)
	{
		if(end > interval[i].second)
		{
			right = interval[i].second;
		}
		else
			right = end;
		//right = end>interval[i].second ? interval[i].second : end;
		if(right-interval[i].first>=0)
		{
			cover = right - interval[i].first + 1;
		}
		else
			cover = 0;
		//cover = right-interval[i].first>=0 ? right-interval[i].first+1 : 0;
		if(cover > maxcover)
		{
			maxcover = cover;
			m = i;
			n = temp;
		}
		if(interval[i].second > end)
		{
			end = interval[i].second;
			temp = i;
		}
	}

	cout<<maxcover<<endl;
	cout<<m<<endl;
	cout<<n<<endl;
	cout<<"["<<interval[m].first<<","<<interval[m].second<<"]"<<endl;
	cout<<"["<<interval[n].first<<","<<interval[n].second<<"]"<<endl;
	
	return 0;
}

bool cmp(pair<int,int> a, pair<int,int>b)
{
	return a.first<b.first;
}
