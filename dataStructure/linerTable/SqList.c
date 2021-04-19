/*
---------------------【线性表】顺序表------------------------

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
    -插入
    -删除
    -对表中的每个元素调用指定函数

-----------------使用方法：#include"文件名.c" 即可调用函数---------------
*/

//定义
#define MaxSize 10 //定义最大长度
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];	//用静态数组存放最大元素
    int length;				//顺序表的当前长度
}SqList;					//顺序表的类型定义

//初始化
/*
操作条件：构造一个空的线性表L
*/
void InitList(SqList *L)
{
	int i;
	for(i = 0; i < MaxSize; i++)
		L->data[i] = -2;	//将所有元素初始化
    L->length = 0;    		//顺序表初始长度为0
}

//销毁——由静态数组构建的线性表在生命周期结束后会被系统回收，无需手动销毁

//置空
/*
初始条件：线性表L已存在
操作条件：将L置为空表
*/
void Blanking(SqList *L)
{
	if(L->length <= 0)
		return;
	int i;
	for(i = 0; i < MaxSize; i++)
		L->data[i] = -2;	
    L->length = 0;    
}

//判空
/*
初始条件：线性表L已存在
操作条件：若L为空表，则返回1，否则返回0
*/
int ListEmpty(SqList *L)
{
	if(L->length < 0)
		return 0;
	return (L->length == 0)?1:0;
}

//求表长
/*
初始条件：线性表L已存在
操作条件：返回L中元素的个数
可以用，没必要
*/
int ListLength(SqList *L)
{
	return L->length;
}

//按序查找
/*
初始条件：线性表L已存在，1 <= i <=ListLength(L)
操作条件：用e返回L中第i个元素的值
可以有，没必要
*/
void GetElem(SqList *L, int i, int *e)
{
	if(L->length <= 0)
		return;
	if(i <= L->length && i > 0)
		e = &L->data[i-1];
	else
		e = 0;
}

//按值查找
/*
初始条件：线性表L已存在
操作条件：返回L中第一个与值为e的数据元素的位序，若这样的值不存在，返回n(使用者指定)
*/
int Locate(SqList *L, ElemType var, int n)
{
	if(L->length <= 0)
		return;
	int i;
	for(i = 0; i < L->length; i++)
	{
		if(L->data[i] == var)
			return i;
	}
	return n;
}

//查前驱
/*
初始条件：线性表L已存在
操作条件：若cur_e是L的数据元素，且不是第一个，用pre_e返回它的前驱，否则操作失败，pre_e无定义
*/
void PriorElem(SqList *L, ElemType cur_e, ElemType *pre_e)
{
	if(L->length <= 0)
		return;
	if(cur_e == L->data[0])
		return;
	int i;
	//确保cur_e是表中数据
	for(i = 1; i < L->length; i++)
	{
		if(cur_e == L->data[i])
		break;
	}
	if(i == L->length)
		return;
	pre_e = &L->data[i - 1];
}

//查后继
/*
初始条件：线性表L已存在
操作条件：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，pre_e无定义
*/
void NextElem(SqList *L, ElemType cur_e, ElemType *next_e)
{
	if(L->length <= 0)
		return;
	if(cur_e == L->data[L->length - 1])
		return;
	int i;
	//确保cur_e是表中数据
	for(i = 0; i < L->length - 1; i++)
	{
		if(cur_e == L->data[i])
		break;
	}
	if(i == L->length - 1)
		return;
	next_e = &L->data[i + 1];
}

//插入——按序插入
/*
初始条件：线性表L已存在，1 <= i <= ListLength(L)+1
操作条件：在L的第i个位置之前插入新的数据元素e，L的长度加一
*/
void ListInsert(SqList *L, int i, ElemType e) 
{
	if(L->length <= 0)
		return;
	int j;
	for(j = L->length; j >= i; j++)		//将第i个元素之后的元素后移
		L->data[j] = L->data[j-1];		//L是一个结构体指针，因此使用 -> 访问变量

	L->data[i-1] = e;
	L->length++;
}

//删除——按序删除
/*
初始条件：线性表L已存在，且为非空，1 <= i <=ListLength(L)
操作条件：删除L的第i个数据元素，并用e返回其值，L的长度减一
*/
int ListDelete(SqList *L, int i, ElemType *e) 
{
	if(L->length <= 0)
		return 0;
	if(i<1 || i>L->length)
		return 0;
	e =  &L->data[i-1];
	int j;
	for(j = i; j < L->length; j++)
		L->data[j-1] = L->data[j];
	L->length--;
	return 1;
}

//对表中的每个元素调用指定函数
/*
初始条件：线性表L已存在
操作条件：依次对L的每个数据元素调用visit()。一旦visit()失败，则操作失败
*/
void ListTraverse(SqList *L)
{
	if(L->length <= 0)
		return;
 	int i;
 	for(i = 0; i < L->length; i++)
    {
		visit(L->data[i]);
	}
}
