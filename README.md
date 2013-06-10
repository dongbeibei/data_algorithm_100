data_algorithm_100
==================

100 test questions

This project is just a test one.

The total questions is list:

1.把二元查找树转变成排序的双向链表
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
10
/ \
6 14
/ \ / \
4 8 12 16
转换成双向链表
4=6=8=10=12=14=16。
首先我们定义的二元查找树节点的数据结构如下：
struct BSTreeNode
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};

2.设计包含min 函数的栈。
定义栈的数据结构，要求添加一个min 函数，能够得到栈的最小元素。
要求函数min、push 以及pop 的时间复杂度都是O(1)。
3.求子数组的最大和
题目：
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。
4.在二元树中找出和为某一值的所有路径
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
3
例如输入整数22 和如下二元树
10
/ \
5 12
/ \
4 7
则打印出两条路径：10, 12 和10, 5, 7。
二元树节点的数据结构定义为：
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
};
5.查找最小的k 个元素
题目：输入n 个整数，输出其中最小的k 个。
例如输入1，2，3，4，5，6，7 和8 这8 个数字，则最小的4 个数字为1，2，3 和4。
第6 题
腾讯面试题：
给你10 分钟时间，根据上排给出十个数，在其下排填出对应的十个数
要求下排每个数都是先前上排那十个数在下排出现的次数。
上排的十个数如下：
【0，1，2，3，4，5，6，7，8，9】
举一个例子，
数值: 0,1,2,3,4,5,6,7,8,9
分配: 6,2,1,0,0,0,1,0,0,0
0 在下排出现了6 次，1 在下排出现了2 次，
2 在下排出现了1 次，3 在下排出现了0 次....
以此类推..
第7 题
微软亚院之编程判断俩个链表是否相交
给出俩个单向链表的头指针，比如h1，h2，判断这俩个链表是否相交。
为了简化问题，我们假设俩个链表均不带环。
4
问题扩展：
1.如果链表可能有环列?
2.如果需要求出俩个链表相交的第一个节点列?
第8 题
此贴选一些比较怪的题，，由于其中题目本身与算法关系不大，仅考考思维。特此并作一题。
1.有两个房间，一间房里有三盏灯，另一间房有控制着三盏灯的三个开关，
这两个房间是分割开的，从一间里不能看到另一间的情况。
现在要求受训者分别进这两房间一次，然后判断出这三盏灯分别是由哪个开关控制的。
有什么办法呢？
2.你让一些人为你工作了七天，你要用一根金条作为报酬。金条被分成七小块，每天给出一
块。
如果你只能将金条切割两次，你怎样分给这些工人?
3. ★用一种算法来颠倒一个链接表的顺序。现在在不用递归式的情况下做一遍。
★用一种算法在一个循环的链接表里插入一个节点，但不得穿越链接表。
★用一种算法整理一个数组。你为什么选择这种方法?
★用一种算法使通用字符串相匹配。
★颠倒一个字符串。优化速度。优化空间。
★颠倒一个句子中的词的顺序，比如将“我叫克丽丝”转换为“克丽丝叫我”，
实现速度最快，移动最少。
★找到一个子字符串。优化速度。优化空间。
★比较两个字符串，用O(n)时间和恒量空间。
★假设你有一个用1001 个整数组成的数组，这些整数是任意排列的，但是你知道所有
的整数都在1 到1000(包括1000)之间。此外，除一个数字出现两次外，其他所有数字只出
现一次。假设你只能对这个数组做一次处理，用一种算法找出重复的那个数字。如果你在运
算中使用了辅助的存储方式，那么你能找到不用这种方式的算法吗?
★不用乘法或加法增加8 倍。现在用同样的方法增加7 倍。
第9 题
判断整数序列是不是二元查找树的后序遍历结果
题目：输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。
如果是返回true，否则返回false。
例如输入5、7、6、9、11、10、8，由于这一整数序列是如下树的后序遍历结果：
5
8
/ \
6 10
/ \ / \
5 7 9 11
因此返回true。
如果输入7、4、6、5，没有哪棵树的后序遍历的结果是这个序列，因此返回false。
第10 题
翻转句子中单词的顺序。
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
例如输入“I am a student.”，则输出“student. a am I”。
第11 题
求二叉树中节点的最大距离...
如果我们把二叉树看成一个图，父子节点之间的连线看成是双向的，
我们姑且定义"距离"为两节点之间边的个数。
写一个程序，
求一棵二叉树中相距最远的两个节点之间的距离。
第12 题
题目：求1+2+…+n，
要求不能使用乘除法、for、while、if、else、switch、case 等关键字以及条件判断语句
（A?B:C）。
第13 题：
题目：输入一个单向链表，输出该链表中倒数第k 个结点。链表的倒数第0 个结点为链表的
尾指针。
链表结点定义如下：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
6
第14 题：
题目：输入一个已经按升序排序过的数组和一个数字，
在数组中查找两个数，使得它们的和正好是输入的那个数字。
要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
例如输入数组1、2、4、7、11、15 和数字15。由于4+11=15，因此输出4 和11。
第15 题：
题目：输入一颗二元查找树，将该树转换为它的镜像，
即在转换后的二元查找树中，左子树的结点都大于右子树的结点。
用递归和循环两种方法完成树的镜像转换。
例如输入：
8
/ \
6 10
/\ /\
5 7 9 11
输出：
8
/ \
10 6
/\ /\
11 9 7 5
定义二元查找树的结点为：
struct BSTreeNode // a node in the binary search tree (BST)
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};
第16 题：
题目（微软）：
输入一颗二元树，从上往下按层打印树的每个结点，同一层中按照从左往右的顺序打印。
例如输入
7
8
/ \
6 10
/ \ / \
5 7 9 11
输出8 6 10 5 7 9 11。
第17 题：
题目：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
分析：这道题是2006 年google 的一道笔试题。
第18 题：
题目：n 个数字（0,1,…,n-1）形成一个圆圈，从数字0 开始，
每次从这个圆圈中删除第m 个数字（第一个为当前数字本身，第二个为当前数字的下一个数
字）。
当一个数字删除后，从被删除数字的下一个继续删除第m 个数字。
求出在这个圆圈中剩下的最后一个数字。
July：我想，这个题目，不少人已经见识过了。
第19 题：
题目：定义Fibonacci 数列如下：
/ 0 n=0
f(n)= 1 n=1
\ f(n-1)+f(n-2) n=2
输入n，用最快的方法求该数列的第n 项。
分析：在很多C 语言教科书中讲到递归函数的时候，都会用Fibonacci 作为例子。
因此很多程序员对这道题的递归解法非常熟悉，但....呵呵，你知道的。。
第20 题：
题目：输入一个表示整数的字符串，把该字符串转换成整数并输出。
例如输入字符串"345"，则输出整数345。
8
第21 题
2010 年中兴面试题
编程求解：
输入两个整数n 和m，从数列1，2，3.......n 中随意取几个数,
使其和等于m ,要求将其中所有的可能组合列出来.
第22 题：
有4 张红色的牌和4 张蓝色的牌，主持人先拿任意两张，再分别在A、B、C 三人额头上贴任
意两张牌，
A、B、C 三人都可以看见其余两人额头上的牌，看完后让他们猜自己额头上是什么颜色的牌，
A 说不知道，B 说不知道，C 说不知道，然后A 说知道了。
请教如何推理，A 是怎么知道的。
如果用程序，又怎么实现呢？
第23 题：
用最简单，最快速的方法计算出下面这个圆形是否和正方形相交。"
3D 坐标系原点(0.0,0.0,0.0)
圆形:
半径r = 3.0
圆心o = (*.*, 0.0, *.*)
正方形:
4 个角坐标;
1:(*.*, 0.0, *.*)
2:(*.*, 0.0, *.*)
3:(*.*, 0.0, *.*)
4:(*.*, 0.0, *.*)
第24 题：
链表操作，
（1）.单链表就地逆置，
（2）合并链表
第25 题：
写一个函数,它的原形是int continumax(char *outputstr,char *intputstr)
9
功能：
在字符串中找出连续最长的数字串，并把这个串的长度返回，
并把这个最长数字串付给其中一个函数参数outputstr 所指内存。
例如："abcd12345ed125ss123456789"的首地址传给intputstr 后，函数将返回9，
outputstr 所指的值为123456789
26.左旋转字符串
题目：
定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。
如把字符串abcdef 左旋转2 位得到字符串cdefab。请实现字符串左旋转的函数。
要求时间对长度为n 的字符串操作的复杂度为O(n)，辅助内存为O(1)。
27.跳台阶问题
题目：一个台阶总共有n 级，如果一次可以跳1 级，也可以跳2 级。
求总共有多少总跳法，并分析算法的时间复杂度。
这道题最近经常出现，包括MicroStrategy 等比较重视算法的公司
都曾先后选用过个这道题作为面试题或者笔试题。
28.整数的二进制表示中1 的个数
题目：输入一个整数，求该整数的二进制表达中有多少个1。
例如输入10，由于其二进制表示为1010，有两个1，因此输出2。
分析：
这是一道很基本的考查位运算的面试题。
包括微软在内的很多公司都曾采用过这道题。
29.栈的push、pop 序列
题目：输入两个整数序列。其中一个序列表示栈的push 顺序，
10
判断另一个序列有没有可能是对应的pop 顺序。
为了简单起见，我们假设push 序列的任意两个整数都是不相等的。
比如输入的push 序列是1、2、3、4、5，那么4、5、3、2、1 就有可能是一个pop 系列。
因为可以有如下的push 和pop 序列：
push 1，push 2，push 3，push 4，pop，push 5，pop，pop，pop，pop，
这样得到的pop 序列就是4、5、3、2、1。
但序列4、3、5、1、2 就不可能是push 序列1、2、3、4、5 的pop 序列。
30.在从1 到n 的正数中1 出现的次数
题目：输入一个整数n，求从1 到n 这n 个整数的十进制表示中1 出现的次数。
例如输入12，从1 到12 这些整数中包含1 的数字有1，10，11 和12，1 一共出现了5 次。
分析：这是一道广为流传的google 面试题。
31.华为面试题：
一类似于蜂窝的结构的图，进行搜索最短路径（要求5 分钟）
32.
有两个序列a,b，大小都为n,序列元素的值任意整数，无序；
要求：通过交换a,b 中的元素，使[序列a 元素的和]与[序列b 元素的和]之间的差最小。
例如:
var a=[100,99,98,1,2, 3];
var b=[1, 2, 3, 4,5,40];
33.
实现一个挺高级的字符匹配算法：
给一串很长字符串，要求找到符合要求的字符串，例如目的串：123
1******3***2 ,12*****3 这些都要找出来
其实就是类似一些和谐系统。。。。。
11
34.
实现一个队列。
队列的应用场景为：
一个生产者线程将int 类型的数入列，一个消费者线程将int 类型的数出列
35.
求一个矩阵中最大的二维矩阵(元素和最大).如:
1 2 0 3 4
2 3 4 5 1
1 1 5 3 0
中最大的是:
4 5
5 3
要求:(1)写出算法;(2)分析时间复杂度;(3)用C 写出关键代码
第36 题-40 题（有些题目搜集于CSDN 上的网友，已标明）：
36.引用自网友：longzuo
谷歌笔试：
n 支队伍比赛，分别编号为0，1，2。。。。n-1，已知它们之间的实力对比关系，
存储在一个二维数组w[n][n]中，w[i][j] 的值代表编号为i，j 的队伍中更强的一支。
所以w[i][j]=i 或者j，现在给出它们的出场顺序，并存储在数组order[n]中，
比如order[n] = {4,3,5,8,1......}，那么第一轮比赛就是4 对3， 5 对8。.......
胜者晋级，败者淘汰，同一轮淘汰的所有队伍排名不再细分，即可以随便排，
下一轮由上一轮的胜者按照顺序，再依次两两比，比如可能是4 对5,直至出现第一名
编程实现，给出二维数组w，一维数组order 和用于输出比赛名次的数组result[n]，
求出result。
37.
有n 个长为m+1 的字符串，
如果某个字符串的最后m 个字符与某个字符串的前m 个字符匹配，则两个字符串可以联接，
问这n 个字符串最多可以连成一个多长的字符串，如果出现循环，则返回错误。
12
38.
百度面试：
1.用天平（只能比较，不能称重）从一堆小球中找出其中唯一一个较轻的，使用x 次天平，
最多可以从y 个小球中找出较轻的那个，求y 与x 的关系式。
2.有一个很大很大的输入流，大到没有存储器可以将其存储下来，
而且只输入一次，如何从这个输入流中随机取得m 个记录。
3.大量的URL 字符串，如何从中去除重复的，优化时间空间复杂度
39.
网易有道笔试：
(1).
求一个二叉树中任意两个节点间的最大距离，
两个节点的距离的定义是这两个节点间边的个数，
比如某个孩子节点和父节点间的距离是1，和相邻兄弟节点间的距离是2，优化时间空间复
杂度。
(2).
求一个有向连通图的割点，割点的定义是，如果除去此节点和与其相关的边，
有向图不再连通，描述算法。
40.百度研发笔试题
引用自：zp155334877
1)设计一个栈结构，满足一下条件：min，push，pop 操作的时间复杂度为O(1)。
2)一串首尾相连的珠子(m 个)，有N 种颜色(N<=10)，
设计一个算法，取出其中一段，要求包含所有N 中颜色，并使长度最短。
并分析时间复杂度与空间复杂度。
3)设计一个系统处理词语搭配问题，比如说中国和人民可以搭配，
则中国人民人民中国都有效。要求：
*系统每秒的查询数量可能上千次；
*词语的数量级为10W；
*每个词至多可以与1W 个词搭配
当用户输入中国人民的时候，要求返回与这个搭配词组相关的信息。
13
41.求固晶机的晶元查找程序
晶元盘由数目不详的大小一样的晶元组成，晶元并不一定全布满晶元盘，
照相机每次这能匹配一个晶元，如匹配过，则拾取该晶元，
若匹配不过，照相机则按测好的晶元间距移到下一个位置。
求遍历晶元盘的算法求思路。
42.请修改append 函数，利用这个函数实现：
两个非降序链表的并集，1->2->3 和2->3->5 并为1->2->3->5
另外只能输出结果，不能修改两个链表的数据。
43.递归和非递归俩种方法实现二叉树的前序遍历。
44.腾讯面试题：
1.设计一个魔方（六面）的程序。
2.有一千万条短信，有重复，以文本文件的形式保存，一行一条，有重复。
请用5 分钟时间，找出重复出现最多的前10 条。
3.收藏了1 万条url，现在给你一条url，如何找出相似的url。（面试官不解释何为相似）
45.雅虎：
1.对于一个整数矩阵，存在一种运算，对矩阵中任意元素加一时，需要其相邻（上下左右）
某一个元素也加一，现给出一正数矩阵，判断其是否能够由一个全零矩阵经过上述运算得到。
2.一个整数数组，长度为n，将其分为m 份，使各份的和相等，求m 的最大值
比如{3，2，4，3，6} 可以分成{3，2，4，3，6} m=1;
{3,6}{2,4,3} m=2
{3,3}{2,4}{6} m=3 所以m 的最大值为3
46.搜狐：
四对括号可以有多少种匹配排列方式？比如两对括号可以有两种：（）（）和（（））
14
47.创新工场：
求一个数组的最长递减子序列比如{9，4，3，2，5，4，3，2}的最长递减子序列为{9，5，
4，3，2}
48.微软：
一个数组是由一个递减数列左移若干位形成的，比如{4，3，2，1，6，5}
是由{6，5，4，3，2，1}左移两位形成的，在这种数组中查找某一个数。
49.一道看上去很吓人的算法面试题：
如何对n 个数进行排序，要求时间复杂度O(n)，空间复杂度O(1)
50.网易有道笔试：
1.求一个二叉树中任意两个节点间的最大距离，两个节点的距离的定义是这两个节点间边
的个数，
比如某个孩子节点和父节点间的距离是1，和相邻兄弟节点间的距离是2，优化时间空间复
杂度。
2.求一个有向连通图的割点，割点的定义是，
如果除去此节点和与其相关的边，有向图不再连通，描述算法。
-------------------------------------------------------------------
51.和为n 连续正数序列。
题目：输入一个正数n，输出所有和为n 连续正数序列。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3 个连续序列1-5、4-6 和7-8。
分析：这是网易的一道面试题。
52.二元树的深度。
题目：输入一棵二元树的根结点，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为
树的深度。
15
例如：输入二元树：
10
/ \
6 14
/ / \
4 12 16
输出该树的深度3。
二元树的结点定义如下：
struct SBinaryTreeNode // a node of the binary tree
{
int m_nValue; // value of node
SBinaryTreeNode *m_pLeft; // left child of node
SBinaryTreeNode *m_pRight; // right child of node
};
分析：这道题本质上还是考查二元树的遍历。
53.字符串的排列。
题目：输入一个字符串，打印出该字符串中字符的所有排列。
例如输入字符串abc，则输出由字符a、b、c 所能排列出来的所有字符串
abc、acb、bac、bca、cab 和cba。
分析：这是一道很好的考查对递归理解的编程题，
因此在过去一年中频繁出现在各大公司的面试、笔试题中。
54.调整数组顺序使奇数位于偶数前面。
题目：输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，
所有偶数位于数组的后半部分。要求时间复杂度为O(n)。
55.
题目：类CMyString 的声明如下：
class CMyString
{
public:
CMyString(char* pData = NULL);
16
CMyString(const CMyString& str);
~CMyString(void);
CMyString& operator = (const CMyString& str);
private:
char* m_pData;
};
请实现其赋值运算符的重载函数，要求异常安全，即当对一个对象进行赋值时发生异常，对
象的状态不能改变。
56.最长公共字串。
题目：如果字符串一的所有字符按其在字符串中的顺序出现在另外一个字符串二中，
则字符串一称之为字符串二的子串。
注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。
请编写一个函数，输入两个字符串，求它们的最长公共子串，并打印出最长公共子串。
例如：输入两个字符串BDCABA 和ABCBDAB，字符串BCBA 和BDAB 都是是它们的最长公共子
串，
则输出它们的长度4，并打印任意一个子串。
分析：求最长公共子串（Longest Common Subsequence, LCS）是一道非常经典的动态规划
题，
因此一些重视算法的公司像MicroStrategy 都把它当作面试题。
57.用俩个栈实现队列。
题目：某队列的声明如下：
template<typename T> class CQueue
{
public:
CQueue() {}
~CQueue() {}
void appendTail(const T& node); // append a element to tail
17
void deleteHead(); // remove a element from head
private:
T> m_stack1;
T> m_stack2;
};
分析：从上面的类的声明中，我们发现在队列中有两个栈。
因此这道题实质上是要求我们用两个栈来实现一个队列。
相信大家对栈和队列的基本性质都非常了解了：栈是一种后入先出的数据容器，
因此对队列进行的插入和删除操作都是在栈顶上进行；队列是一种先入先出的数据容器，
我们总是把新元素插入到队列的尾部，而从队列的头部删除元素。
58.从尾到头输出链表。
题目：输入一个链表的头结点，从尾到头反过来输出每个结点的值。链表结点定义如下：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
分析：这是一道很有意思的面试题。
该题以及它的变体经常出现在各大公司的面试、笔试题中。
59.不能被继承的类。
题目：用C++设计一个不能被继承的类。
分析：这是Adobe 公司2007 年校园招聘的最新笔试题。
这道题除了考察应聘者的C++基本功底外，还能考察反应能力，是一道很好的题目。
60.在O（1）时间内删除链表结点。
题目：给定链表的头指针和一个结点指针，在O(1)时间删除该结点。链表结点的定义如下：
18
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
函数的声明如下：
void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted);
分析：这是一道广为流传的Google 面试题，能有效考察我们的编程基本功，还能考察我们
的反应速度，
更重要的是，还能考察我们对时间复杂度的理解。
-------------------------------------------------------------------------
61.找出数组中两个只出现一次的数字
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
分析：这是一道很新颖的关于位运算的面试题。
62.找出链表的第一个公共结点。
题目：两个单向链表，找出它们的第一个公共结点。
链表的结点定义为：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};
19
分析：这是一道微软的面试题。微软非常喜欢与链表相关的题目，
因此在微软的面试题中，链表出现的概率相当高。
63.在字符串中删除特定的字符。
题目：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They
are students.”和”aeiou”，
则删除之后的第一个字符串变成”Thy r stdnts.”。
分析：这是一道微软面试题。在微软的常见面试题中，与字符串相关的题目占了很大的一部
分，
因为写程序操作字符串能很好的反映我们的编程基本功。
64. 寻找丑数。
题目：我们把只包含因子2、3 和5 的数称作丑数（Ugly Number）。例如6、8 都是丑数，
但14 不是，因为它包含因子7。习惯上我们把1 当做是第一个丑数。
求按从小到大的顺序的第1500 个丑数。
分析：这是一道在网络上广为流传的面试题，据说google 曾经采用过这道题。
65.输出1 到最大的N 位数
题目：输入数字n，按顺序输出从1 最大的n 位10 进制数。比如输入3，
则输出1、2、3 一直到最大的3 位数即999。
分析：这是一道很有意思的题目。看起来很简单，其实里面却有不少的玄机。
66.颠倒栈。
题目：用递归颠倒一个栈。例如输入栈{1, 2, 3, 4, 5}，1 在栈顶。
颠倒之后的栈为{5, 4, 3, 2, 1}，5 处在栈顶。
20
67.俩个闲玩娱乐。
1.扑克牌的顺子
从扑克牌中随机抽5 张牌，判断是不是一个顺子，即这5 张牌是不是连续的。
2-10 为数字本身，A 为1，J 为11，Q 为12，K 为13，而大小王可以看成任意数字。
2.n 个骰子的点数。
把n 个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，
打印出S 的所有可能的值出现的概率。
68.把数组排成最小的数。
题目：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的
一个。
例如输入数组{32, 321}，则输出这两个能排成的最小数字32132。
请给出解决问题的算法，并证明该算法。
分析：这是09 年6 月份百度的一道面试题，
从这道题我们可以看出百度对应聘者在算法方面有很高的要求。
69.旋转数组中的最小元素。
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个
排好序的数组的一个旋转，
输出旋转数组的最小元素。例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数
组的最小值为1。
分析：这道题最直观的解法并不难。从头到尾遍历数组一次，就能找出最小的元素，
时间复杂度显然是O(N)。但这个思路没有利用输入数组的特性，我们应该能找到更好的解
法。
70.给出一个函数来输出一个字符串的所有排列。
ANSWER 简单的回溯就可以实现了。当然排列的产生也有很多种算法，去看看组合数学，
还有逆序生成排列和一些不需要递归生成排列的方法。
21
印象中Knuth 的<TAOCP>第一卷里面深入讲了排列的生成。这些算法的理解需要一定的数学
功底，
也需要一定的灵感，有兴趣最好看看。
71.数值的整数次方。
题目：实现函数double Power(double base, int exponent)，求base 的exponent 次方。
不需要考虑溢出。
分析：这是一道看起来很简单的问题。可能有不少的人在看到题目后30 秒写出如下的代码：
double Power(double base, int exponent)
{
double result = 1.0;
for(int i = 1; i <= exponent; ++i)
result *= base;
return result;
}
72.
题目：设计一个类，我们只能生成该类的一个实例。
分析：只能生成一个实例的类是实现了Singleton 模式的类型。
73.对策字符串的最大长度。
题目：输入一个字符串，输出该字符串中对称的子字符串的最大长度。
比如输入字符串“google”，由于该字符串里最长的对称子字符串是“goog”，因此输出4。
分析：可能很多人都写过判断一个字符串是不是对称的函数，这个题目可以看成是该函数的
加强版。
22
74.数组中超过出现次数超过一半的数字
题目：数组中有一个数字出现的次数超过了数组长度的一半，找出这个数字。
分析：这是一道广为流传的面试题，包括百度、微软和Google 在内的多家公司都
曾经采用过这个题目。要几十分钟的时间里很好地解答这道题，
除了较好的编程能力之外，还需要较快的反应和较强的逻辑思维能力。
75.二叉树两个结点的最低共同父结点
题目：二叉树的结点定义如下：
struct TreeNode
{
int m_nvalue;
TreeNode* m_pLeft;
TreeNode* m_pRight;
};
输入二叉树中的两个结点，输出这两个结点在数中最低的共同父结点。
分析：求数中两个结点的最低共同结点是面试中经常出现的一个问题。这个问题至少有两个
变种。
76.复杂链表的复制
题目：有一个复杂链表，其结点除了有一个m_pNext 指针指向下一个结点外，
还有一个m_pSibling 指向链表中的任一结点或者NULL。其结点的C++定义如下：
struct ComplexNode
{
int m_nValue;
ComplexNode* m_pNext;
ComplexNode* m_pSibling;
};
下图是一个含有5 个结点的该类型复杂链表。
图中实线箭头表示m_pNext 指针，虚线箭头表示m_pSibling 指针。为简单起见，
指向NULL 的指针没有画出。
请完成函数ComplexNode* Clone(ComplexNode* pHead)，以复制一个复杂链表。
23
分析：在常见的数据结构上稍加变化，这是一种很新颖的面试题。
要在不到一个小时的时间里解决这种类型的题目，我们需要较快的反应能力，
对数据结构透彻的理解以及扎实的编程功底。
77.关于链表问题的面试题目如下：
1.给定单链表，检测是否有环。
使用两个指针p1,p2 从链表头开始遍历，p1 每次前进一步，p2 每次前进两步。如果p2 到
达链表尾部，
说明无环，否则p1、p2 必然会在某个时刻相遇(p1==p2)，从而检测到链表中有环。
2.给定两个单链表(head1, head2)，检测两个链表是否有交点，如果有返回第一个交点。
如果head1==head2，那么显然相交，直接返回head1。
否则，分别从head1,head2 开始遍历两个链表获得其长度len1 与len2，假设len1>=len2，
那么指针p1 由head1 开始向后移动len1-len2 步，指针p2=head2，
下面p1、p2 每次向后前进一步并比较p1p2 是否相等，如果相等即返回该结点，
否则说明两个链表没有交点。
3.给定单链表(head)，如果有环的话请返回从头结点进入环的第一个节点。
运用题一，我们可以检查链表中是否有环。
如果有环，那么p1p2 重合点p 必然在环中。从p 点断开环，
方法为：p1=p, p2=p->next, p->next=NULL。此时，原单链表可以看作两条单链表，
一条从head 开始，另一条从p2 开始，于是运用题二的方法，我们找到它们的第一个交点即
为所求。
4.只给定单链表中某个结点p(并非最后一个结点，即p->next!=NULL)指针，删除该结点。
办法很简单，首先是放p 中数据,然后将p->next 的数据copy 入p 中，接下来删除p->next
即可。
5.只给定单链表中某个结点p(非空结点)，在p 前面插入一个结点。
办法与前者类似，首先分配一个结点q，将q 插入在p 后，接下来将p 中的数据copy 入q
中，
然后再将要插入的数据记录在p 中。
24
78.链表和数组的区别在哪里？
分析：主要在基本概念上的理解。
但是最好能考虑的全面一点，现在公司招人的竞争可能就在细节上产生，
谁比较仔细，谁获胜的机会就大。
79.
1.编写实现链表排序的一种算法。说明为什么你会选择用这样的方法？
2.编写实现数组排序的一种算法。说明为什么你会选择用这样的方法？
3.请编写能直接实现strstr()函数功能的代码。
80.阿里巴巴一道笔试题
问题描述:
12 个高矮不同的人,排成两排,每排必须是从矮到高排列,而且第二排比对应的第一排的人
高,问排列方式有多少种?
这个笔试题,很YD,因为把某个递归关系隐藏得很深。
81.第1 组百度面试题
1.一个int 数组，里面数据无任何限制，要求求出所有这样的数a[i]，
其左边的数都小于等于它，右边的数都大于等于它。
能否只用一个额外数组和少量其它空间实现。
2.一个文件，内含一千万行字符串，每个字符串在1K 以内，
要求找出所有相反的串对，如abc 和cba。
3.STL 的set 用什么实现的？为什么不用hash？
82.第2 组百度面试题
1.给出两个集合A 和B，其中集合A={name}，
集合B={age、sex、scholarship、address、...}，
要求：
问题1、根据集合A 中的name 查询出集合B 中对应的属性信息；
问题2、根据集合B 中的属性信息（单个属性，如age<20 等），查询出集合A 中对应的name。
2.给出一个文件，里面包含两个字段{url、size}，
25
即url 为网址，size 为对应网址访问的次数，
要求：
问题1、利用Linux Shell 命令或自己设计算法，
查询出url 字符串中包含“baidu”子字符串对应的size 字段值；
问题2、根据问题1 的查询结果，对其按照size 由大到小的排列。
（说明：url 数据量很大，100 亿级以上）
83.第3 组百度面试题
1.今年百度的一道题目
百度笔试：给定一个存放整数的数组，重新排列数组使得数组左边为奇数，右边为偶数。
要求：空间复杂度O(1)，时间复杂度为O（n）。
2.百度笔试题
用C 语言实现函数void * memmove(void *dest, const void *src, size_t n)。
memmove 函数的功能是拷贝src 所指的内存内容前n 个字节到dest 所指的地址上。
分析：
由于可以把任何类型的指针赋给void 类型的指针
这个函数主要是实现各种数据类型的拷贝。
84.第4 组百度面试题
2010 年3 道百度面试题[相信，你懂其中的含金量]
1.a~z 包括大小写与0~9 组成的N 个数
用最快的方式把其中重复的元素挑出来。
2.已知一随机发生器，产生0 的概率是p，产生1 的概率是1-p，现在要你构造一个发生器，
使得它构造0 和1 的概率均为1/2；构造一个发生器，使得它构造1、2、3 的概率均为1/3；...，
构造一个发生器，使得它构造1、2、3、...n 的概率均为1/n，要求复杂度最低。
3.有10 个文件，每个文件1G，
每个文件的每一行都存放的是用户的query，每个文件的query 都可能重复。
要求按照query 的频度排序.
85.又见字符串的问题
1.给出一个函数来复制两个字符串A 和B。
字符串A 的后几个字节和字符串B 的前几个字节重叠。
分析：记住，这种题目往往就是考你对边界的考虑情况。
2.已知一个字符串，比如asderwsde,寻找其中的一个子字符串比如sde 的个数，
如果没有返回0，有的话返回子字符串的个数。
26
86.
怎样编写一个程序，把一个有序整数数组放到二叉树中？
分析:本题考察二叉搜索树的建树方法，简单的递归结构。
关于树的算法设计一定要联想到递归，因为树本身就是递归的定义。
而，学会把递归改称非递归也是一种必要的技术。
毕竟，递归会造成栈溢出，关于系统底层的程序中不到非不得以最好不要用。
但是对某些数学问题，就一定要学会用递归去解决。
87.
1.大整数数相乘的问题。（这是2002 年在一考研班上遇到的算法题）
2.求最大连续递增数字串（如“ads3sl456789DF3456ld345AA”中的“456789”）
3.实现strstr 功能，即在父串中寻找子串首次出现的位置。
（笔试中常让面试者实现标准库中的一些函数）
88.2005 年11 月金山笔试题。编码完成下面的处理函数。
函数将字符串中的字符'*'移到串的前部分，
前面的非'*'字符后移，但不能改变非'*'字符的先后顺序，函数返回串中字符'*'的数量。
如原始串为：ab**cd**e*12，
处理后为*****abcde12，函数并返回值为5。（要求使用尽量少的时间和辅助空间）
89.神州数码、华为、东软笔试题
1.2005 年11 月15 日华为软件研发笔试题。实现一单链表的逆转。
2.编码实现字符串转整型的函数（实现函数atoi 的功能），据说是神州数码笔试题。如将字
符
串”+123”123, ”-0123”-123, “123CS45”123, “123.45CS”123, “CS123.45”0
3.快速排序（东软喜欢考类似的算法填空题，又如堆排序的算法等）
4.删除字符串中的数字并压缩字符串。
如字符串”abc123de4fg56”处理后变为”abcdefg”。注意空间和效率。
（下面的算法只需要一次遍历，不需要开辟新空间，时间复杂度为O(N)）
5.求两个串中的第一个最长子串（神州数码以前试题）。
如"abractyeyt","dgdsaeactyey"的最大子串为"actyet"。
27
90.
1.不开辟用于交换数据的临时空间，如何完成字符串的逆序
(在技术一轮面试中，有些面试官会这样问)。
2.删除串中指定的字符
（做此题时，千万不要开辟新空间，否则面试官可能认为你不适合做嵌入式开发）
3.判断单链表中是否存在环。
91.
1.一道著名的毒酒问题
有1000 桶酒，其中1 桶有毒。而一旦吃了，毒性会在1 周后发作。
现在我们用小老鼠做实验，要在1 周内找出那桶毒酒，问最少需要多少老鼠。
2.有趣的石头问题
有一堆1 万个石头和1 万个木头，对于每个石头都有1 个木头和它重量一样，
把配对的石头和木头找出来。
92.
1.多人排成一个队列,我们认为从低到高是正确的序列,但是总有部分人不遵守秩序。
如果说,前面的人比后面的人高(两人身高一样认为是合适的),
那么我们就认为这两个人是一对“捣乱分子”,比如说,现在存在一个序列:
176, 178, 180, 170, 171
这些捣乱分子对为
<176, 170>, <176, 171>, <178, 170>, <178, 171>, <180, 170>, <180, 171>,
那么,现在给出一个整型序列,请找出这些捣乱分子对的个数(仅给出捣乱分子对的数目即可,
不用具体的对)
要求：
输入:
为一个文件(in)，文件的每一行为一个序列。序列全为数字，数字间用”,”分隔。
输出：
为一个文件(out)，每行为一个数字，表示捣乱分子的对数。
详细说明自己的解题思路，说明自己实现的一些关键点。
并给出实现的代码，并分析时间复杂度。
限制：
输入每行的最大数字个数为100000 个，数字最长为6 位。程序无内存使用限制。
28
93.在一个int 数组里查找这样的数，它大于等于左侧所有数，小于等于右侧所有数。
直观想法是用两个数组a、b。a[i]、b[i]分别保存从前到i 的最大的数和从后到i 的最小
的数，
一个解答：这需要两次遍历，然后再遍历一次原数组，
将所有data[i]>=a[i-1]&&data[i]<=b[i]的data[i]找出即可。
给出这个解答后，面试官有要求只能用一个辅助数组，且要求少遍历一次。
94.微软笔试题
求随机数构成的数组中找到长度大于=3 的最长的等差数列9 d- x' W) w9 ?" o3 b0 R
输出等差数列由小到大:
如果没有符合条件的就输出
格式：
输入[1,3,0,5,-1,6]
输出[-1,1,3,5]
要求时间复杂度，空间复杂度尽量小
95.华为面试题
1 判断一字符串是不是对称的，如：abccba
2.用递归的方法判断整数组a[N]是不是升序排列
96.08 年中兴校园招聘笔试题
1．编写strcpy 函数
已知strcpy 函数的原型是
char *strcpy(char *strDest, const char *strSrc);
其中strDest 是目的字符串，strSrc 是源字符串。不调用C++/C 的字符串库函数，请
编写函数strcpy
最后压轴之戏，终结此微软等100 题系列V0.1 版。
那就，
连续来几组微软公司的面试题，让你一次爽个够：
======================
97.第1 组微软较简单的算法面试题
1.编写反转字符串的程序，要求优化速度、优化空间。
29
2.在链表里如何发现循环链接？
3.编写反转字符串的程序，要求优化速度、优化空间。
4.给出洗牌的一个算法，并将洗好的牌存储在一个整形数组里。
5.写一个函数，检查字符是否是整数，如果是，返回其整数值。
（或者：怎样只用4 行代码编写出一个从字符串到长整形的函数？）
98.第2 组微软面试题
1.给出一个函数来输出一个字符串的所有排列。
2.请编写实现malloc()内存分配函数功能一样的代码。
3.给出一个函数来复制两个字符串A 和B。字符串A 的后几个字节和字符串B 的前几个字节
重叠。
4.怎样编写一个程序，把一个有序整数数组放到二叉树中？
5.怎样从顶部开始逐层打印二叉树结点数据？请编程。
6.怎样把一个链表掉个顺序（也就是反序，注意链表的边界条件并考虑空链表）？
99.第3 组微软面试题
1.烧一根不均匀的绳，从头烧到尾总共需要1 个小时。
现在有若干条材质相同的绳子，问如何用烧绳的方法来计时一个小时十五分钟呢？
2.你有一桶果冻，其中有黄色、绿色、红色三种，闭上眼睛抓取同种颜色的两个。
抓取多少个就可以确定你肯定有两个同一颜色的果冻？（5 秒-1 分钟）
3.如果你有无穷多的水，一个3 公升的提捅，一个5 公升的提捅，两只提捅形状上下都不均
匀，
问你如何才能准确称出4 公升的水？（40 秒-3 分钟）
一个岔路口分别通向诚实国和说谎国。
来了两个人，已知一个是诚实国的，另一个是说谎国的。
诚实国永远说实话，说谎国永远说谎话。现在你要去说谎国，
但不知道应该走哪条路，需要问这两个人。请问应该怎么问？（20 秒-2 分钟）
100.第4 组微软面试题，挑战思维极限
1.12 个球一个天平，现知道只有一个和其它的重量不同，问怎样称才能用三次就找到那个
球。
13 个呢？（注意此题并未说明那个球的重量是轻是重，所以需要仔细考虑）（5 分钟-1 小时）
2.在9 个点上画10 条直线，要求每条直线上至少有三个点？（3 分钟-20 分钟）
3.在一天的24 小时之中，时钟的时针、分针和秒针完全重合在一起的时候有几次？
都分别是什么时间？你怎样算出来的？（5 分钟-15 分钟）
30
终结附加题：
微软面试题，挑战你的智商
==========
说明：如果你是第一次看到这种题，并且以前从来没有见过类似的题型，
并且能够在半个小时之内做出答案，说明你的智力超常..）
1.第一题. 五个海盗抢到了100 颗宝石，每一颗都一样大小和价值连城。他们决定这么分：
抽签决定自己的号码（1、2、3、4、5）
首先，由1 号提出分配方案，然后大家表决，当且仅当超过半数的人同意时，
按照他的方案进行分配，否则将被扔进大海喂鲨鱼
如果1 号死后，再由2 号提出分配方案，然后剩下的4 人进行表决，
当且仅当超过半数的人同意时，按照他的方案进行分配，否则将被扔入大海喂鲨鱼。
依此类推
条件：每个海盗都是很聪明的人，都能很理智地做出判断，从而做出选择。
问题：第一个海盗提出怎样的分配方案才能使自己的收益最大化？
2.一道关于飞机加油的问题，已知：
每个飞机只有一个油箱，
飞机之间可以相互加油（注意是相互，没有加油机）
一箱油可供一架飞机绕地球飞半圈，
问题：
为使至少一架飞机绕地球一圈回到起飞时的飞机场，至少需要出动几架飞机？
（所有飞机从同一机场起飞，而且必须安全返回机场，不允许中途降落，中间没有飞机场）
