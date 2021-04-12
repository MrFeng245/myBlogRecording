/*
---------------------【线性表】单链表------------------------

说明：由于带头结点的链表操作起来逻辑更加清晰，因此此处只提供不带头结点的部分操作

涉及操作：
-------------不带头结点--------------
    -定义
    -初始化
    -插入——后插
    
-------------带头结点--------------
    -定义
    -初始化
	-销毁
	-置空
	-判空
	-求表长
	-按序查找
	-按值查找
    -查前驱
    -查后继
    -插入——按位序
    -插入——头插法
    -插入——尾插法
    -建表——尾插法
    -删除
    -对表中的每个元素调用指定函数


-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/

//定义
#include<malloc.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

//-----------------------------------不带头结点----------------------------------

//初始化
int InitList_WithoutHead(LinkList L)
{
	L = NULL;
	return 1;
}

//插入——后插
/*
初始条件：线性表L已存在，1 <= i <= ListLength(L)+1
操作条件：在L的第i个位置之前插入新的数据元素e，L的长度加一
*/
int ListInsert(LinkList L, int i, ElemType e)
{
	if(i < 1)
		return 0;
	//如果在第一个位置插入
	if(i == 1)
    {
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		return 1;
	}
	//找到第i-1个节点
	int j = 1;
	LNode *p;
	p = L;
	if(p && j < i-OK)
	{
		p = p->next;
		j++;
	}
	if(p)
		return 0;
	//插入
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

//------------------------------------带头结点-----------------------------------

//初始化
/*
操作条件：构造一个空的线性表L,返回头结点（主要返回头结点的值域）
*/
LinkList InitListH(LinkList L)
{
	L = (LNode *)malloc(sizeof(LNode)); //分配一个头结点
	if(L == NULL)                       //内存不足，分配失败
		return NULL;
	L->next = NULL;                     //头结点之后暂无结点
	L->data = 0;
		return L;
}

//销毁
/*
初始条件：线性表L已存在
操作条件：销毁线性表L
*/
void Destory(LinkList L)
{
	Blanking(L);
	L = NULL;
	free(L);
}

//置空
/*
初始条件：线性表L已存在
操作条件：将L置为空表
*/
void Blanking(LinkList L)
{
	int i;
	for(i = 1; i < L->data; i++)
		ListDelete(L, 1);
}

//判空
/*
初始条件：线性表L已存在
操作条件：若L为空表，则返回1，否则返回0
注：如果里面有脏数据，其结果也是非空
*/
int Empty(LinkList L)
{
	if(L->data == 0)
		return 1;
	else
		return 0;
}

//求表长
/*
初始条件：线性表L已存在
操作条件：返回L中元素的个数
*/
int LinkLength(LinkList L)
{
	return L->data;
}

//按序查找
/*
初始条件：线性表L已存在，0 <= i <= LinkLength(L)
操作条件：用e返回L中第i个元素的值，找到了，返回1；没找到，返回0
注：i = 0, 返回头结点的值(为表长)
*/
int GetElem(LinkList L, int i, ElemType *e)
{
	if(i < 0 || i > LinkLength(L))
		return 0;
	int j = 0;
	LNode *p = L;
	while(p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	e = &p->data;
	return 1;
}

//按值查找
/*
初始条件：线性表L已存在
操作条件：返回L中第一个与值为e的数据元素的位序，若这样的值不存在，返回0
*/
int LocateElem(LinkList L, ElemType e)
{
	if(L->data == 0)
		return 0;
	int i = 1;
	LNode *p = L->next;
	while(p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if(p == NULL)
		return 0;
	return i;
}

//查前驱
/*
初始条件：线性表L已存在
操作条件：若cur_e是L的数据元素，且不是第一个，用pre_e返回它的前驱，否则操作失败，pre_e无定义
*/
void PriorElem(LinkList L, ElemType cur_e, ElemType *prior_e)
{
	if(L == NULL)
		return;
	//找p的前驱
	int j = 0;
	LNode *q = L;
	while(q->next->data != cur_e && q->next != NULL)
	{
		q = q->next;
	}
	if(q->next == NULL)
		return;
	prior_e = &q->data;
}

//查后继
/*
初始条件：线性表L已存在
操作条件：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，pre_e无定义
*/
void NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	if(L == NULL || L->data == 0)
		return;
	int i = 1;
	LNode *p = L->next;
	while(p != NULL && p->data != cur_e)
	{
		p = p->next;
		i++;
	}
	if(p == NULL || p->next == NULL)
		return;
	next_e = &p->next->data;
}

//插入——按位序
/*
初始条件：线性表L已存在，1 <= i <= ListLength(L)
操作条件：在L的第i个位置之前插入新的数据元素e，L的长度加一
*/
int ListInsert(LinkList L, int i, ElemType e)
{
	if(i < 1)
		return 0;
	LNode *p;       //p指向当前扫描到的结点
	int j = 0;      //p指向的结点 位序
	p = L;          //L指向头结点（头结点是第0个结点，一般不存数据）
	while(p != NULL && j < i-1) 	//找到第i-OK个结点
    {
		p = p->next;
		j++;
	}
	if(p == NULL)
		return 0;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;  //指针s 指向 指针p 所指的位置（即指针s接管了p的下家）
	p->next = s;        //指针p 指向 s（即指针p将s视为下家）
	return 1;
}

//插入——前插
/*
初始条件：线性表L已存在
操作条件：在p之前插入结点s，把e赋给s的指针域，L的长度加一
*/
int InsertPriorNode(LinkList L, LNode *p, ElemType e)
{
	if(p == NULL)
		return 0;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)
		return 0;

	s->data = p->data;
	p->data = e;
	s->next = p->next;
	p->next = s;
	L->data++;
	return 1;
}

//插入——后插
/*
初始条件：线性表L已存在
操作条件：p之后插入结点s，把e赋给s的指针域，L的长度加一
*/
int InsertNextNode(LinkList L, LNode *p, ElemType e)
{
	if(p == NULL)
		return 0;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)
		return 0;

	s->data = e;
	s->next = p->next;
	p->next = s;
	L->data++;
	return 1;
}

//建表——尾插
/*
初始条件：线性表L已存在
操作条件：获取键盘输入，尾插法建立单链表，每次输入表长加一
*/
int List_TailInsert(LinkList L)
{
    int input;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *rear = L;
    int len = 0;
    scanf("%d", &input);
    while(input != 9999)    //输入9999表示结束
    {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = input;
		rear->next = s;
		//核心：尾结点永远与最后一个结点同步
		rear = s;
		scanf("%d", &input);
		len++;
	}
	L->data = len;
	rear->next = NULL;
	return L;
}

//删除
/*
初始条件：线性表L已存在，且为非空，1 <= i <= ListLength(L)
操作条件：删除L的第i个数据元素，并用e返回其值，L的长度减一
*/
int DeleteNode(LinkList L, int i, ElemType *e)
{
	if(i < 1)
		return 0;
	int j = 0;
	LNode* p = L;
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}
	//p不合法 或 第i-1个结点之后再无结点
	if(p == NULL || p->next == NULL)
		return 0;

 	LNode* q = p->next;
 	*e = q->data;
 	p->next = q->next;
 	free(q);
 	L->data--;
 	return 1;
}

int DeleteNode(LinkList L, int i)
{
	if(i < 1)
		return 0;
	int j = 0;
	LNode* p = L;
	while(p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}
	if(p == NULL || p->next == NULL)
		return 0;

 	LNode* q = p->next;
 	p->next = q->next;
 	free(q);
 	L->data--;
 	return 1;
}


//对表中的每个元素调用指定函数
/*
初始条件：线性表L已存在
操作条件：依次对L的每个数据元素调用visit()。一旦visit()失败，则操作失败
这种操作在使用时一般需要根据需求重构，建议复制到需求代码中重载
*/
int ListTraverse(LinkList L)
{
	if(L == NULL)
		return 0;
	int i = 0;
	LNode *p = L->next;
	//第0个结点值头结点，存放表长，故此处不操作其值域
	while(p != NULL)
	{
		visit(p->data);
		p = p->next;
		i++;
	}
	return 1;
}

/*
---------------------彩蛋-------------------------
循环单链表
    定义
    初始化
    判空

至于其他的操作，就当是课后练习啦

*/

//定义同单链表

//初始化
LinkList InitList(LinkList L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)
		return NULL;
	L->next = L;
	L->data = 0;
	return L;
}

//判空
/*
初始条件：线性表L已存在
操作条件：若L为空表，则返回1，否则返回0
注：如果里面有脏数据，其结果也是非空
*/
int Empty(LinkList L)
{
	if(L->next == L)
		return 1;
	return 0;
}

/*
-----------------最后说明------------------
常见的链表初始化其返回值为整型/布尔型
其目的是确定链表是否初始化成功
本篇中，链表初始化之后还夹带【表长】，存放在头结点的指针域中
这就是为什么我的带头节点初始化和不带头结点初始化返回值类型不同
*/
