/*
题目描述：请编写程序，找出下面“输入数据及格式”中所描述的
输入数据文件中最大重叠区间的大小。

对一个正整数n，如果n在数据文件中某行的两个正整数（假设为A和B）
之间，即A<=n<=B或A>=n>=B，则n属于该行；如果n同时属于行i和j，则i和j有
重叠区间；重叠区间的大小是同时属于行i和j的整数个数。

例如，行（10 20）和（12 25）的重叠区间为[12 20]，其大小为9；
行（20 10）和（12 18）的重叠区间为[10 12]，其大小为3；
行(20 10)和（20 30）的重叠区间大小为1。

输入数据：程序读入已被命名为input.txt的输入数据文本文件，该文件的
行数在1到1,000,000之间，每行有用一个空格分隔的2个正整数，
这2个正整数的大小次序随机，每个数都在1和2^32-1之间。
（为便于调试，您可下载测试input.txt文件，实际运行时我们会使用
不同内容的输入文件。）

输出数据：在标准输出上打印出输入数据文件中最大重叠区间的大小，
如果所有行都没有重叠区间，则输出0。

评分标准：程序输出结果必须正确，内存使用必须不超过256MB，
程序的执行时间越快越好。


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
	int		a, b, x, i;
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

	for(i=1 ; i<interval.size() ; i++)
	{
		right = end>interval[i].second ? interval[i].second : end;
		cover = right-interval[i].first>=0 ? right-interval[i].first+1 : 0;
		if(cover > maxcover)
			maxcover = cover;
		if(interval[i].second > end)
			end = interval[i].second;
	}

	cout<<maxcover<<endl;
	
	return 0;
}

bool cmp(pair<int,int> a, pair<int,int>b)
{
	return a.first<b.first;
}
