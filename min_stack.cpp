/*
 * implement a stack, let push(), pop(), min() to be O(1)
 * author: dongbeibei
 * building time: 2013/6/9
 * modifing time: 
 */


#include <iostream>
#include "base.h"

using namespace std;

typedef struct my_stack
{
	ElemType			data;
	struct my_stack		*next;
}*my_p_stack;

typedef struct _min_stack
{
	struct my_stack		*top;
	struct my_stack		*min;
}min_s_stack, *min_p_stack;

class min_stack
{
public:
	min_stack();
	~min_stack();

	bool push(ElemType &);
	ElemType pop();
	bool empty();
	ElemType &min();
	void data_visit();
	void min_visit();

private:
	min_p_stack use;
};

int main(void)
{
	int dataset[] = {7,8,3,4,5,2,1,7};
	int data_pop, data_min;

	min_stack *test = new min_stack;

	for(int i=0 ; i<sizeof(dataset)/sizeof(int) ; i++)
	{
		test->push(dataset[i]);
		test->data_visit();
		test->min_visit();
	}

	while(!test->empty())
	{
		data_min = test->min();
		data_pop = test->pop();
		cout<<"current min: "<<data_min<<", pop: "<<data_pop<<endl;
	}

	delete test;
	test = NULL;

	return 0;
}

min_stack::min_stack()
{
	use = new _min_stack;
	if(!use)
		cout<<"init fail\n";

	use->top = NULL;
	use->min = NULL;
}

min_stack::~min_stack()
{
	if(use)
	{
		my_p_stack freeptr = NULL;

		while(use->top)
		{
			freeptr = use->top;
			use->top = use->top->next;

			delete freeptr;
		}

		while(use->min)
		{
			freeptr = use->min;
			use->min = use->min->next;

			delete freeptr;
		}
	}

	use = NULL;
}

bool min_stack::push(ElemType &e)
{
	my_p_stack item = new my_stack;
	my_p_stack min = new my_stack;

	if(!(item&&min))
		cout<<"new fail, push fail\n";

	item->data = e;
	min->data = e;

	if(use->top && use->min)
	{
		if(e < use->min->data)
			min->data = e;
		else
			min->data = use->min->data;
	}

	item->next = use->top;
	use->top = item;

	min->next = use->min;
	use->min = min;

	return true;
}

ElemType min_stack::pop()
{
	ElemType e;

	if(use)
	{
		my_p_stack freeptr = NULL;

//		if(!((use->top && use->min) || (!use->top && !use->min)))
//			exit(0);

		if(use->top && use->min)
		{
			e = use->top->data;

			freeptr = use->top;
			use->top = use->top->next;

			delete freeptr;

			freeptr = use->min;
			use->min = use->min->next;

			delete freeptr;
		}
	}

	return e;
}

bool min_stack::empty()
{
	return (use->top==NULL)&&(use->min==NULL);
}

ElemType &min_stack::min()
{
	if(use->min && use->top)
		return use->min->data;
}

void min_stack::data_visit()
{
	my_stack	*p;

	p = use->top;
	cout<<"data visit:\t";
	while(p)
	{
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

void min_stack::min_visit()
{
	my_stack	*p;

	p = use->min;
	cout<<"min visit:\t";
	while(p)
	{
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}