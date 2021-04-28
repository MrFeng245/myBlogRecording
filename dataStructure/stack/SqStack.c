/*（操作受限的顺序表）
---------------------【栈】顺序存储-----------------------
Catalan:[1/(n+1)]*[2n里取n个]
涉及操作：
    -定义
    -初始化
	-置空
	-判空
	-求表长
	-按序查找
	-按值查找
    -读栈顶
    -查队尾
    -进栈
    -出栈
-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/
#include<malloc.h>
#define MaxSize 10
#define ElemType int


//定义
typedef struct
{
	ElemType data[MaxSize];
	int top;    //栈顶指针
}SqStack;

//初始化
/*
操作条件：构造一个空的顺序栈
*/
void InitStack(SqStack *S)
{
	S->top = -1;
}


//销毁——数组，自动回收


//置空
/*
初始条件：顺序栈已存在
操作条件：将L置为空表
*/
void Blanking(SqStack *S)
{
	if(S->top < 0)
		return;
	int i;
    for(i = 0; S->top >= 0; i++)
		S->top = S->top - 1;
}

//判空
/*
初始条件：顺序栈已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int IsEmpty(SqStack S)
{
	if(S.top == -1)
		return 1;
	else
		return 0;
}

//求表长
/*
初始条件：顺序栈已存在
操作条件：返回L中元素的个数
如果头结点值域不存表长，这个函数就很重要了
*/
int GetLen(SqStack S)
{
	int len;
	for(len = 0; S.top >= 0; len++)
		S.top = S.top - 1;
	return len;
}

//按序查找
/*
初始条件：顺序栈已存在，1 <= i <=ListLength(L)
操作条件：用e返回L中第i个元素的值
*/
int GetElem(SqStack S, int i)
{
	if(i <= 0 || i > GetLen(S))
		return 0;
	return S.data[GetLen(S) - i];
	/*
    如果希望从表头（即栈底）开始查找，此处逻辑为
    return S.data[i - 1];
	*/
}

//按值查找
/*
初始条件：顺序栈已存在
操作条件：返回L中第一个与值为e的数据元素的位序，若这样的值不存在，返回0
*/
int Locate(SqStack S, ElemType var)
{
	if(S.top < 0)
		return 0;
	int i = 0;
	do{
        S.top = S.top - 1;
        i++;
	}while(var != S.data[i] && S.top >= 0);
	//如果最后一个也不是
	if(S.top < 0 && S.data[0] != var)
		return 0;
	//此处返回的位序是从栈顶算起
	return i;
}

//读栈顶
/*
初始条件：顺序栈已存在
*/
int GetTop(SqStack S)
{
	if(S.top == -1)
		return 0;
	return S.data[S.top];
}

//读栈顶
/*
初始条件：顺序栈已存在
*/
int GetRear(SqStack S)
{
	if(S.top == -1)
		return 0;
	return S.data[0];
}

//入栈
/*
初始条件：顺序栈已存在
*/
int Push(SqStack *S, ElemType x)
{
	if(S->top == MaxSize - 1)
		return 0;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return 1;
}


//出栈
/*
初始条件：顺序栈已存在，且为非空
*/
int Pop(SqStack *S, int *x)
{
	if(S->top == -1)
		return 0;
	*x = S->data[S->top];
	S->top = S->top - 1;
	return 1;
}
