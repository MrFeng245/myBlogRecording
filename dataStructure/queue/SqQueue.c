/*（操作受限的顺序表）
---------------------【队列】顺序存储-----------------------

涉及操作：
    -定义
    -初始化
	-销毁
	-置空
	-判空
	-求队长
    -入队
    -出队

-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/
#include<malloc.h>
#define MaxSize 10
#define ElemType int
//定义
typedef struct
{
	ElemType data[MaxSize]; //用静态数组存放队列元素
	int front,rear;         //队头指针和队尾指针
}SqQueue;                  

//初始化
/*
操作条件：构造一个空的队列
*/
void InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
}

//销毁——OS自动回收

//置空
/*
初始条件：队列已存在
操作条件：将L置为空表
*/
int Blanking(SqQueue *Q)
{
	int len;
	len = Length(*Q);
	if(len <= 0)
		return 0;
	int i, x = 0;
	for(i = 0; i < len; i++)
		DeQueue(Q, &x);
	return 1;
}


//判空
/*
初始条件：队列已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int QueueEmpty(SqQueue Q)
{
	if(Q.rear == Q.front)
		return 1;
	else
		return 0;
}

//求队列元素的个数
/*
初始条件：队列已存在
操作条件：返回队列中元素的个数  （rear + MaxSize - front）%MaxSize
*/
int Length(SqQueue Q)
{
	return (Q.rear + MaxSize - Q.front) % MaxSize;
}

//查队头元素
/*
初始条件：队列已存在,且不为空
操作条件：通过x返回队列的head指向的值
*/
int GetHead(SqQueue Q, ElemType *x)
{
	if(Q.rear == Q.front)
		return 0;
	x = Q.data[Q.front];
	return 1;
}

//查队尾元素
/*
初始条件：队列已存在,且不为空
操作条件：通过x返回队列的rear指向的值
*/
int GetRear(SqQueue Q, ElemType *x)
{
	if(Q.front == Q.rear)
		return 0;
	x = Q.data[Q.rear];
	return 1;
}


//入队
/*
初始条件：队列已存在
操作条件：判断队列是否存满，如果存满，return 0，否则入队，return 1
*/
//判满/空不浪费一个存储空间的方法
//法一：在结构体里设置size，记录队列长度
//法二：在结构体里设置tag，最近一次插入为0；删除为1
int EnQueue(SqQueue *Q, ElemType x)
{
	if(Q->rear + 1 == Q->front)         //牺牲一个存储单元
		return 0;
	Q->data[Q->rear] = x;    				//将x插入到队尾
	Q->rear = (Q->rear + 1)%MaxSize;		//队尾指针后移一位(循环队列)
	return 1;
}

//出队
/*
初始条件：队列已存在，且为非空
操作条件：x返回出队元素的值，队列指针向后移一位
*/
int DeQueue(SqQueue *Q, ElemType *x)
{
	if(Q->rear == Q->front)
		return 0;
	x = Q->data[Q->front];
	Q->front = (Q->front + 1)%MaxSize;
	return 1;
}
