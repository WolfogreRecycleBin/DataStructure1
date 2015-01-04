#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"	// 辅助软件包

//基于课本给的SeqStack.h做的修改,增加top2的定义和操作，部分操作省略注释了

// 顺序栈模板类
template<class ElemType>
class SeqStack 
{
protected:
// 顺序栈的数据成员:
	int top1;										// 栈顶指针 
	int top2;
	int maxSize;									// 栈的最大容量 
	ElemType *elems;								// 元素存储空间

public:
//  顺序栈的方法声明及重载编译系统默认方法声明:
	SeqStack(int size = DEFAULT_SIZE);				// 构造函数
	virtual ~SeqStack();							// 析构函数
	int GetLength(int c) const;							// 求栈的长度			 
	bool IsEmpty(int c) const;							// 判断栈是否为空
	void Clear(int c);									// 将栈清空
	void Traverse(void (*Visit)(const ElemType &),int c) const;	// 遍历栈
	Status Push(const ElemType e,int c);				    // 入栈
	Status Top(ElemType &e,int c) const;				    // 取顶元素
	Status Pop(ElemType &e,int c);					    // 出栈
	//SeqStack(const SeqStack<ElemType> &s);		// 复制构造函数
	//SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // 赋值语句重载
	void Show()
	{
		for(int i=0;i<maxSize;i++)
		{
			if(i>top1 && i<top2)
				cout<<"* ";
			else
				cout<<elems[i]<<" ";
		}
		cout<<endl;
	}
};


// 顺序栈类的实现部分

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// 操作结果：构造一个最大容量为size的空栈
{
	maxSize = size;						// 栈的最大容量
	//if (elems != NULL) delete []elems;	// 释放已有存储空间
	elems = new ElemType[maxSize];		// 分配新的存储空间
	top1 = -1;
	top2 = maxSize;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// 操作结果：销毁栈
{
	delete []elems;					// 释放栈的存储空间
}

template <class ElemType>
int SeqStack<ElemType>::GetLength(int c) const
// 操作结果：返回栈中元素个数
{
	if(c==1)return top1 + 1;
	return maxSize-top2;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty(int c) const
// 操作结果：如栈为空，则返回true，否则返回false
{
	if(c==1)return top1 == -1;
	return top2==maxSize;
}

template<class ElemType>
void SeqStack<ElemType>::Clear(int c)
// 操作结果：清空栈
{
	if(c==1)top1 = -1;
	top2=maxSize;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &),int c) const
// 操作结果：从栈顶到栈底依次对栈的每个元素调用函数(*visit)访问 
{
	if(c==1) for (int i = top1; i >=0 ; i--) 
		(*Visit)(elems[i]);
	for (int i = top2; i <maxSize ; i++) 
		(*Visit)(elems[i]);
}

template<class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e,int c)
// 操作结果：将元素e追加到栈顶,如成功则返加SUCCESS,如栈已满将返回OVER_FLOW
{
	if (top1+1 == top2) // 栈已满
		return OVER_FLOW;
	if(c==1)
	{
		elems[++top1] = e;	// 将元素e追加到栈顶 
		return SUCCESS;
	}
	elems[--top2] = e;	// 将元素e追加到栈顶 
	return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e,int c) const
// 操作结果：如栈非空,用e返回栈顶元素,函数返回SUCCESS,否则函数返回UNDER_FLOW
{
	if(c==1 && IsEmpty(1))	 // 栈空
		return UNDER_FLOW;
	if(c==2 && IsEmpty(2))	 // 栈空
		return UNDER_FLOW;
	
	if(c==1)e = elems[top1];	// 用e返回栈顶元素
	return SUCCESS;
	e = elems[top2];	// 用e返回栈顶元素
	return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e,int c)
// 操作结果：如栈非空,删除栈顶元素,并用e返回栈顶元素,函数返回SUCCESS,否则
// 函数返回UNDER_FLOW
{
	if (c==1 && IsEmpty(1))	 // 栈空
		return UNDER_FLOW;
	if (c==2 && IsEmpty(2))	 // 栈空
		return UNDER_FLOW;
	if(c==1) 
	{
		e = elems[top1--]; // 用e返回栈顶元素
		return SUCCESS;
	}
	e = elems[top2++]; // 用e返回栈顶元素
	return SUCCESS;
}

/*template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s) 
// 操作结果：由栈s构造新栈--复制构造函数
{
    maxSize = s.maxSize;			    // 栈的最大容量 
    if (elems != NULL) delete []elems;	// 释放已有存储空间
    elems = new ElemType[maxSize];		// 分配存储空间
	top = s.top;					    // 复制栈顶指针 
	for (int i = 0; i <= top; i++)      // 从栈底到栈顶对栈s的每个元素进行复制
		elems[i] = s.elems[i];
}*/

/*template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// 操作结果：将栈s赋值给当前栈--赋值语句重载
{
	if (&s != this)	{
	    maxSize = s.maxSize;			    // 栈的最大容量 
	    if (elems != NULL) delete []elems;	// 释放已有存储空间
	    elems = new ElemType[maxSize];		// 分配存储空间
		top = s.top;					    // 复制栈顶指针 
		for (int i = 0; i <= top; i++)		// 从栈底到栈顶对栈s的每个元素进行复制
			elems[i] = s.elems[i];
	}
	return *this;
}*/

#endif
