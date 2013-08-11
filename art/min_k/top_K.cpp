/*
 * 题目描述:
 * 搜索引擎会通过日志文件把用户每次检索使用的所有检索串都记录
 * 下来，每个查询串的长度为1-255字节。假设目前有一千万个记录
 * （这些查询串的重复度比较高，虽然总数是1千万，但如果除去重复
 * 后，不超过3百万个。一个查询串的重复度越高，说明查询它的用户
 * 越多，也就是越热门），请你统计最热门的10个查询串，要求使用的
 * 内存不能超过1G。
 *
 * hash + min heap
 */


#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#define HASHLEN 2807303
#define WORDLEN 30

typedef struct node_no_space *ptr_no_space;
typedef struct node_has_space *ptr_has_space;
ptr_no_space head[HASHLEN];

struct node_no_space
{
	char	*word;
	int		count;
	ptr_no_space next;
};

struct node_has_space
{
	char	*word;
	int		count;
	ptr_has_space next;
};

int hash_function(char const *p);
void append_word(char const *str);
void write_to_file();
void sift_down(node_has_space heap[], int i, int len);
void build_min_heap(node_has_space heap[], int len);
void handle_symbol(char *str, int n);

int main(void)
{
	char str[WORDLEN];

	for(int i=0 ; i<HASHLEN ; ++i)
	{
		head[i] = NULL;
	}

	FILE *fp_passage = fopen("string.txt", "r");
	assert(fp_passage);
	while(fscanf(fp_passage, "%s", str) != EOF)
	{
		int n = strlen(str) - 1;
		if(n > 0)
			handle_symbol(str, n);
		append_word(str);
	}
	fclose(fp_passage);

	write_to_file();

	int n = 10;
	ptr_has_space heap = new node_has_space[n+1];

	int c;
	FILE *fp_word = fopen("result.txt", "r");
	assert(fp_word);
	for(int j=1 ; j<=n ; ++j)
	{
		fscanf(fp_word, "%s %d", &str, &c);
		heap[j].count = c;
		strcpy(heap[j].word, str);
	}
	
	build_min_heap(heap, n);

	while(fscaf(fp_word, "%s %d", &str, &c) != EOF)
	{
		if(c > heap[1].count)
		{
			heap[1].count = c;
			strcpy(heap[1].word, str);
			sift_down(heap, 1, n);
		}
	}
	fclose(fp_word);

	cout<<"result:\n";
	for(int k=1 ; k<=n ; ++k)
		cout<<"\t"<<heap[k].count<<" "<<heap[k].word<<endl;
	cout<<endl;

	return 0;
}

//simple hash function
int hash_function(char const *p)
{
	int value = 0;

	while(*p != '\0')
	{
		value = value * 31 + *p++;
		if(value > HASHLEN)
			value = value % HASHLEN;
	}

	return value;
}

//add word to hash table
void append_word(char const *str)
{
	int index = hash_function(str);
	ptr_no_space p = head[index];

	while(p != NULL)
	{
		if(strcmp(str, p->word) == 0)
		{
			++(p->count);
			return;
		}
		p = p->next;
	}

	ptr_no_space q = new node_no_space;
	q->count = 1;
	q->word = new char[strlen(str)+1];
	strcpy(q->word, str);
	q->next = head[index];
	head[index] = q;
}

//write the word result to file
void write_to_file()
{
	FILE *fp = fopen("result.txt", "w");
	assert(fp);

	int i = 0;
	while(i < HASHLEN)
	{
		for(ptr_no_space p = head[i] ; p!=NULL ; p=p->next)
			fprintf(fp, "%s %d\n", p->word, p->count);
		++i;
	}
	fclose(fp);
}

//keep min heap
void sift_down(node_has_space heap[], int i, int len)
{
	int min_index = -1;
	int left = 2 * i;
	int right = left + 1;

	if(left <= len && heap[left].count < heap[i].count)
		min_index = left;
	else
		min_index = i;

	if(right <= len && heap[right].count < heap[min_index].count)
		min_index = right;

	if(min_index != i)
	{
		swap(heap[i].count, heap[min_index].count);

		char buffer[WORDLEN];
		strcpy(buffer, heap[i].word);
		strcpy(heap[i].word, heap[min_index].word);
		strcpy(heap[min_index].word, buffer);

		sift_down(heap, min_index, len);
	}
}

//build min heap
void build_min_heap(node_has_space heap[], int len)
{
	if(heap == NULL)
		return;

	int index = len / 2;
	for(int i=index ; i>=1 ; --i)
		sift_down(heap, i, len);
}

//handle the symbol in the string
void handle_symbol(char *str, int n)
{
	while(str[n]<'0' || (str[n]>'9'&&str[n]<'A') || (str[n]>'Z'&&str[n]<'a') || str[n]>'z')
	{
		str[n] = '\0';
		--n;
	}

	while(str[0]<'0' || (str[0]>'9'&&str[0]<'A') || (str[0]>'Z'&&str[0]<'a') || str[0]>'z')
	{
		int i = 0;
		while(i < n)
		{
			str[i] = str[i+1];
			++i;
		}
		str[i] = '\0';
		--n;
	}
}
