/*（操作受限的栈）
---------------------【栈】链式存储-----------------------

涉及操作：
    -定义
    -初始化
	-销毁
	-置空
	-判空
	-求栈长
    -查栈顶
    -进栈
    -出栈

-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/
#include<malloc.h>
#define MaxSize 10
#define ElemType int

//定义
typedef struct LinkedStackNode
{
	ElemType data;
	struct LinkedStackNode* next;
}LinkedStackNode, *Linknode;


//初始化
/*
操作条件：构造一个空的链栈
*/
Linknode Init(Linknode top)
{
	top = (LinkedStackNode *)malloc(sizeof(LinkedStackNode)); //分配一个头结点
	if(top == NULL)                       //内存不足，分配失败
		return NULL;
	top->next = NULL;                     //头结点之后暂无结点
	top->data = 0;
		return top;
}

//置空
/*
初始条件：链栈已存在
操作条件：将L置为空表
*/
void Blanking(Linknode S)
{
	int i;
	while(S->data != 0)
		Pop(S);
}


//销毁
/*
初始条件：链栈已存在
操作条件：销毁链栈
*/
void Destory(Linknode S)
{
	Blanking(S);
	S = NULL;
	free(S);
}


//判空
/*
初始条件：链栈已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int Empty(LinkedStackNode top)
{
	if(top.data == 0)
		return 1;
	else
		return 0;
}

//求栈长
/*
初始条件：链栈已存在
操作条件：返回S中元素的个数
如果头结点值域不存表长，这个函数就很重要了
*/
int GetLength(LinkedStackNode top)
{
	return top.data;
}

//读栈顶
/*
初始条件：链栈已存在,且至少有一个元素
*/
int StackTop(Linknode top, int* x)
{
	if(top->data == 0)
		return -1;
	*x = top->next->data;
	return 1;
}


//进栈——单链表的头插法
/*
初始条件：链栈已存在
*/
int Push(Linknode top, ElemType e)
{
	LinkedStackNode *node = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
	if(node == NULL)
		return 0;

	node->next = top->next;
	top->next = node;
	node->data = e;
	top->data++;
	return 1;
}


//出栈——单链表的头删
/*
初始条件：链栈已存在，且为非空
*/
int Pop(Linknode top)
{
	if(Empty(*top) == 1)
		return 0;

	Linknode node;
	node = top->next;
	top->next = node->next;
	top->data--;
	free(node);
}

/*
---------------------【栈】不带头结点的链式存储-----------------------

涉及操作：
    -定义
    -初始化
    -进栈
    -出栈
    -判空

-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/

//定义同上

//初始化
/*
操作条件：构造一个空的链栈
*/
void Init_NoHead(Linknode* top)
{
	*top = NULL;
}


//判空
/*
初始条件：链栈已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int Empty_NoHead(Linknode top)
{
	if(top == NULL)
		return 1;
	else
		return 0;
}



//进栈
/*
初始条件：链栈已存在
*/
int Push_NoHead(Linknode* top, ElemType e)
{
	LinkedStackNode *node = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
	node->next = NULL;
	
	node->data = e;
	node->next = *top;
	*top = node;
	return 1;
}

//出栈
/*
初始条件：链栈已存在，且为非空
*/
void Pop_NoHead(Linknode* top)
{
	Linknode* s;
	s = *top;
	*top = (*top)->next;
	free(s);
	return;
}
