/*
 * function: count the probability of dice's number
 *
 * author:	dongbeibei
 * time:	2013/8/30
 */

#include <iostream>
#include <cmath>

using namespace std;

const int g_maxValue = 6;

void PrintProbability(int number)
{
	if(number < 1)
		return;

	int *Probabilities[2];
	Probabilities[0] = new int[g_maxValue * number + 1];
	Probabilities[1] = new int[g_maxValue * number + 1];

	for(int i=0 ; i<g_maxValue*number+1 ; ++i)
	{
		Probabilities[0][i] = 0;
		Probabilities[1][i] = 0;
	}

	int flag = 0;
	for(int i=1 ; i<=g_maxValue ; ++i)
		Probabilities[flag][i] = 1;

	for(int k=2 ; k<=number ; ++k)
	{
		for(int i=0 ; i<k ; ++i)
			Probabilities[1-flag][i] = 0;

		for(int i=k ; i<=g_maxValue*number ; ++i)
		{
			Probabilities[1-flag][i] = 0;
			for(int j=1 ; j<=i&&j<=g_maxValue ; ++j)
				Probabilities[1-flag][i] += Probabilities[flag][i-j];
		}

		flag = 1 - flag;
	}

	double total = 1.0;
	for(int i=1 ; i<=number ; ++i)
		total *= (double)g_maxValue;

	cout<<"total:\t"<<total<<endl;

	for(int i=number ; i<=g_maxValue*number ; ++i)
	{
		double ratio = (double)Probabilities[flag][i] / total;
		cout<<i<<": "<<Probabilities[flag][i]<<"\t"<<ratio<<endl;
	}

	delete Probabilities[0];
	delete Probabilities[1];
}

//follow: Unit Test
//input 1, 2, 3, 4
void test1();
//input 0
void test2();
//input 10
void test3();

int main(void)
{
	test1();
	cout<<endl;
	test2();
	cout<<endl;
	test3();

	return 0;
}

void test1()
{
	cout<<"Test 1:\n";

	cout<<"number 1:\n";
	PrintProbability(1);
	cout<<"number 2:\n";
	PrintProbability(2);
	cout<<"number 3:\n";
	PrintProbability(3);
	cout<<"number 4:\n";
	PrintProbability(4);
}

void test2()
{
	cout<<"Test 2:\n";

	cout<<"number 0:\n";
	PrintProbability(0);
}

void test3()
{
	cout<<"Test 3:\n";

	cout<<"number 10:\n";
	PrintProbability(10);
}
