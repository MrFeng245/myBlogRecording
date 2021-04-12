/*
---------------------【线性表】双链表------------------------

涉及操作：
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
    -插入——前插
    -插入——后插
    -删除
    对表中的每个元素调用指定函数

-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/

//定义
typedef struct DNode
{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinklist;

//初始化
/*
操作条件：构造一个空的线性表L
*/
DLinklist InitList(DLinklist L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if(L == NULL)
		return NULL;
	L->next = L;
	L->prior = L;
	L->data = 0;
	return L;
}

//销毁
/*
初始条件：线性表L已存在
操作条件：销毁线性表L
*/
void Destory(DLinklist L)
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
void Blanking(DLinklist L)
{
	int i;
	for(i = 1; i < L->data; i++)
		DeleteNode(L, 1);
}

//判空
/*
初始条件：线性表L已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int Empty(DLinklist L)
{
	if(L->next == NULL)
		return 1;
	return 0;
}

//求表长
/*
初始条件：线性表L已存在
操作条件：返回L中元素的个数
如果头结点值域不存表长，这个函数就很重要了
*/
int LinkList(DLinklist L)
{
	return L->data;
}

//按序查找
/*
初始条件：线性表L已存在，1 <= i <=ListLength(L)
操作条件：用e返回L中第i个元素的值
*/
int GetElem(DLinklist L, int i, ElemType *e)
{
	if(i < 0 || i > LinkLength(L))
		return 0;
	int j = 0;
	DNode *p = L;
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
int LocateElem(DLinklist L, ElemType e)
{
	if(L->data == 0)
		return 0;
	int i = 1;
	DNode *p = L->next;
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
void PriorElem(DLinklist L, ElemType cur_e, ElemType *prior_e)
{
	if(L == NULL)
		return;
	int j = 0;
	DNode *q = L->next;
	while(q->data != cur_e && q != NULL)
	{
		q = q->next;
	}
	prior_e = &q->prior->data;
}

//查后继
/*
初始条件：线性表L已存在
操作条件：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，pre_e无定义
*/
void NextElem(DLinklist L, ElemType cur_e, ElemType *next_e)
{
	if(L == NULL || L->data == 0)
		return;
	int i = 1;
	DNode *p = L->next;
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
int ListInsert(DLinklist L, int i, ElemType e)
{
	if(i < 1)
		return 0;
	DNode *p;       
	int j = 0;      
	p = L;          
	while(p != NULL && j < i-1) 	
    {
		p = p->next;
		j++;
	}
	if(p == NULL)
		return 0;
	DNode *s = (DNode *)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	return 1;
}

//插入——前插
/*
初始条件：线性表L已存在
操作条件：在p之前插入结点s，结点p的值域为e，L的长度加一
*/
int InsertPriorNode(LinkList L, DNode *p, ElemType e)
{
	if(p == NULL)
		return 0;
	DNode *s = (DNode *)malloc(sizeof(DNode));
	if(s == NULL)
		return 0;

	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	L->data++;
	return 1;
}

//插入——后插
/*
初始条件：线性表L已存在
操作条件：把结点s插到结点p的后面，L的长度加一
*/
int InsertNextNode(DNode *L, DNode *p, DNode *s)
{
	if(p == NULL || s == NULL)
		return 0;
	s->next = p->next;
	if(p->next != NULL)
		p->next->prior = s;
 	s->prior = p;
	p->next = s;
	L->data++;
	return 1;
}

//删除
/*
初始条件：线性表L已存在，且为非空
操作条件：删除p的后继，L的长度减一
*/
int DeleteNode(DNode *L, DNode *p)
{
	if(p == NULL)
		return ERROR;
	DNode *q = p->next;
	if(q == NULL)
		return ERROR;
	p->next = q->next;
	if(q->next != NULL)
		q->next->prior = p;
	free(q);
	L->data--;
	return OK;
}

/*
---------------------彩蛋-------------------------
循环双链表
    定义
    初始化
    判空
    插入
    删除

至于其他的操作，就当是课后练习啦

*/
//定义同双链表

//初始化
DLinklist InitList(DLinklist L)
{
	L = (DNode *)malloc(sizeof(DNode));
	if(L == NULL)
		return NULL;
	L->next = L;
	L->prior = L;
	L->data = 0;
	return L;
}

//判空
int Empty(DLinklist L)
{
	if(L->next == L)
		return OK;
	return ERROR;
}

//插入
int InsertNextDNode(DNode *L, DNode *p, DNode *s)
{
	if(L == NULL || p == NULL || s == NULL)
		return ERROR;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	L->data++;
	return OK;
}

//删除p的后继q
int DeleteNextDNode(DNode *L, DNode *p, DNode *q)
{
	if(L == NULL || p == NULL || q == NULL)
		return ERROR;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	L->data--;
	return OK;
}

/*
-----------------最后说明------------------
本篇中，链表初始化之后还夹带【表长】，存放在头结点的指针域中
*/
