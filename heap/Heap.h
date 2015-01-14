#ifndef HEAP_H
#define HEAP_H
#include "Assistance.h"					// ���������
enum Type {MIN,MAX,NOT};
template<class ElemType> class Heap{
private:
	Type tag;
	ElemType *heapArr;
	int CurrentSize;
	int MaxSize;
	void FilterDown(int Start);
	void FilterUp(int End);
	Type DetermineType();
public :
	Heap(Type t=NOT,int maxSize);
	Heap(ElemType a[],int maxsize,int n);
	~Heap(){delete [] heapArr;}
	Status Insert(const ElemType &e);
	Status DeleteTop(ElemType & e);
	Status GetTop(ElemType & e)const;
	bool IsEmpty()const{return CurrentSize == 0;}
	bool IsFull()const{return CurrentSize == MaxSize;}
	int SizeOfHeap()const{return CurrentSize;}
	void SetEmpty(){CurrentSize=0;}
	void SetType();
	Type GetType(){return tag;}
	void Traverse(void (*Visit)(const ElemType &)) const;
};
template<class ElemType>
Heap<ElemType>::Heap(Type t,int maxSize)
{
    if (maxSize <= 0)		{
	    cerr << "�ѵĴ�С����С��1" << endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new ElemType[MaxSize];
	tag=t;
	CurrentSize = 0;
}

template<class ElemType>
Heap<ElemType>::Heap(ElemType a[],int maxSize,int n)
{
	if(n <= 0)	{
	    cerr << "�ѵĴ�С����С��1" << endl;
        exit(1);
    }
	MaxSize = maxSize;
	heapArr = new ElemType [MaxSize];
	for (int i = 0; i < n; i++)
        heapArr[i] = a[i];
	CurrentSize = n;
	tag=DetermineType();
}

template<class ElemType>
void Heap<ElemType>::FilterDown(const int Start)
{
	if(tag==NOT) return;
	int i = Start,j;
	ElemType temp = heapArr[i];
	j = 2 * i + 1;
	while(j <= CurrentSize - 1)		{
		if(tag==MIN && j < CurrentSize - 1 && heapArr[j] > heapArr[j+1] || tag==MAX && j < CurrentSize - 1 && heapArr[j] < heapArr[j+1])
			j++;
		//if(temp <= heapArr[j]) break;
		if(tag==MIN && temp <= heapArr[j] || tag==MAX && temp >= heapArr[j]) break;
		else {
			heapArr[i] = heapArr[j];
			i = j;
            j = 2*j+1;
		}
	}
	heapArr[i] = temp;
}

template<class ElemType>
void Heap<ElemType>::FilterUp(int End)
{
	if(tag==NOT) return;
	int j = End,i;
	ElemType temp = heapArr[j];
	i = (j - 1) / 2;
	while(j > 0)	{
		if (tag==MIN && heapArr[i] <= temp || tag==MAX && heapArr[i] >= temp) break;
		else {
			heapArr[j] = heapArr[i];
			j = i;
			i = (j - 1) / 2;
		}
		heapArr[j] = temp;
	}
}

template<class ElemType>
Type Heap<ElemType>::DetermineType()
{
	int flag;
	if(CurrentSize<=0)
	{
		cout<<"Ԫ�ع��٣��������ж��ѵ����ͣ�Ĭ��Ϊ�����."<<endl;
		return NOT;
	}
	flag=1;
	for(int i=0+1;i<CurrentSize;i++)
	{
		if(heapArr[i]<heapArr[(i-1)/2])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"�ж�Ϊ��С��."<<endl;
		return MIN;
	}
	flag=1;
	for(int i=0+1;i<CurrentSize;i++)
	{
		if(heapArr[i]>heapArr[(i-1)/2])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cout<<"�ж�Ϊ����."<<endl;
		return MAX;
	}
	cout<<"�ж�Ϊ�����."<<endl;
	return NOT;
}

template<class ElemType>
Status Heap<ElemType>::Insert(const ElemType &e)
{
	if (IsFull())
		return OVER_FLOW;
	heapArr[CurrentSize] = e;
	FilterUp(CurrentSize);
	CurrentSize++;
	return SUCCESS;
}
	
template<class ElemType>
Status Heap<ElemType>::DeleteTop(ElemType &e)
{
	if(IsEmpty())
    	return UNDER_FLOW;
	e = heapArr[0];
	heapArr[0] = heapArr[CurrentSize-1];
	CurrentSize--;
	FilterDown(0);
	return SUCCESS;
}

template<class ElemType>
Status Heap<ElemType>::GetTop(ElemType &e) const
{
	if(IsEmpty())
    	return UNDER_FLOW;
	e = heapArr[0];
	return SUCCESS;
}

template<class ElemType>
void Heap<ElemType>::SetType()
{
	cout<<"1:��С��"<<endl;
	cout<<"2:����"<<endl;
	cout<<"3:�����"<<endl;
	cout<<"��ѡ�񽫶���Ϊ:"<<endl;
	char c;
	cin>>c;
	if(c=='1')
	{
		tag=MIN;
		int i = (CurrentSize - 2) / 2;
		while(i >= 0)
		{
       		FilterDown(i);
			i--;
		}
		cout<<"��Ϊ��С�ѳɹ�." <<endl;
		return;
	}
	if(c=='2')
	{
		tag=MAX;
		int i = (CurrentSize - 2) / 2;
		while(i >= 0)
		{
       		FilterDown(i);
			i--;
		}
		cout<<"��Ϊ���ѳɹ�." <<endl;
		return;
	}
	if(c=='3')
	{
		tag=NOT;
		cout<<"��Ϊ����ѳɹ�." <<endl;
		return;
	}
	cout<<"��������"<<endl;
}

template<class ElemType>
void Heap<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	for(int i = 0; i < CurrentSize; i++)
		(*Visit)(heapArr[i]);
}
#endif
