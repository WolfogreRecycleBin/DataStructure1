#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"	// ���������

//���ڿα�����SeqStack.h�����޸�,����top2�Ķ���Ͳ��������ֲ���ʡ��ע����

// ˳��ջģ����
template<class ElemType>
class SeqStack 
{
protected:
// ˳��ջ�����ݳ�Ա:
	int top1;										// ջ��ָ�� 
	int top2;
	int maxSize;									// ջ��������� 
	ElemType *elems;								// Ԫ�ش洢�ռ�

public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SeqStack(int size = DEFAULT_SIZE);				// ���캯��
	virtual ~SeqStack();							// ��������
	int GetLength(int c) const;							// ��ջ�ĳ���			 
	bool IsEmpty(int c) const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear(int c);									// ��ջ���
	void Traverse(void (*Visit)(const ElemType &),int c) const;	// ����ջ
	Status Push(const ElemType e,int c);				    // ��ջ
	Status Top(ElemType &e,int c) const;				    // ȡ��Ԫ��
	Status Pop(ElemType &e,int c);					    // ��ջ
	//SeqStack(const SeqStack<ElemType> &s);		// ���ƹ��캯��
	//SeqStack<ElemType> &operator =(const SeqStack<ElemType> &s); // ��ֵ�������
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


// ˳��ջ���ʵ�ֲ���

template<class ElemType>
SeqStack<ElemType>::SeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	//if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top1 = -1;
	top2 = maxSize;
}

template<class ElemType>
SeqStack<ElemType>::~SeqStack()
// �������������ջ
{
	delete []elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int SeqStack<ElemType>::GetLength(int c) const
// �������������ջ��Ԫ�ظ���
{
	if(c==1)return top1 + 1;
	return maxSize-top2;
}

template<class ElemType>
bool SeqStack<ElemType>::IsEmpty(int c) const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	if(c==1)return top1 == -1;
	return top2==maxSize;
}

template<class ElemType>
void SeqStack<ElemType>::Clear(int c)
// ������������ջ
{
	if(c==1)top1 = -1;
	top2=maxSize;
}

template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &),int c) const
// �����������ջ����ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)���� 
{
	if(c==1) for (int i = top1; i >=0 ; i--) 
		(*Visit)(elems[i]);
	for (int i = top2; i <maxSize ; i++) 
		(*Visit)(elems[i]);
}

template<class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e,int c)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,��ջ����������OVER_FLOW
{
	if (top1+1 == top2) // ջ����
		return OVER_FLOW;
	if(c==1)
	{
		elems[++top1] = e;	// ��Ԫ��e׷�ӵ�ջ�� 
		return SUCCESS;
	}
	elems[--top2] = e;	// ��Ԫ��e׷�ӵ�ջ�� 
	return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e,int c) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
	if(c==1 && IsEmpty(1))	 // ջ��
		return UNDER_FLOW;
	if(c==2 && IsEmpty(2))	 // ջ��
		return UNDER_FLOW;
	
	if(c==1)e = elems[top1];	// ��e����ջ��Ԫ��
	return SUCCESS;
	e = elems[top2];	// ��e����ջ��Ԫ��
	return SUCCESS;
}

template<class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e,int c)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,��������SUCCESS,����
// ��������UNDER_FLOW
{
	if (c==1 && IsEmpty(1))	 // ջ��
		return UNDER_FLOW;
	if (c==2 && IsEmpty(2))	 // ջ��
		return UNDER_FLOW;
	if(c==1) 
	{
		e = elems[top1--]; // ��e����ջ��Ԫ��
		return SUCCESS;
	}
	e = elems[top2++]; // ��e����ջ��Ԫ��
	return SUCCESS;
}

/*template<class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s) 
// �����������ջs������ջ--���ƹ��캯��
{
    maxSize = s.maxSize;			    // ջ��������� 
    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
    elems = new ElemType[maxSize];		// ����洢�ռ�
	top = s.top;					    // ����ջ��ָ�� 
	for (int i = 0; i <= top; i++)      // ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
		elems[i] = s.elems[i];
}*/

/*template<class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator = (const SeqStack<ElemType> &s)
// �����������ջs��ֵ����ǰջ--��ֵ�������
{
	if (&s != this)	{
	    maxSize = s.maxSize;			    // ջ��������� 
	    if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	    elems = new ElemType[maxSize];		// ����洢�ռ�
		top = s.top;					    // ����ջ��ָ�� 
		for (int i = 0; i <= top; i++)		// ��ջ�׵�ջ����ջs��ÿ��Ԫ�ؽ��и���
			elems[i] = s.elems[i];
	}
	return *this;
}*/

#endif
