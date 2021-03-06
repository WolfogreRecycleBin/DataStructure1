//int Main.cpp
#include "SeqStack.h"
template<class ElemType>
class BadQueue
{
private:
	SeqStack<ElemType> in,out;
public:
	BadQueue(){;}
	~BadQueue(){;}
	bool IsEmpty()
	{
		if(in.IsEmpty() && out.IsEmpty())
			return true;
		return false;
	}
	void EnQueue(ElemType e)
	{
		cout<<"EnQueue "<<e<<endl;
		in.Push(e);
	}
	void DelQueue()
	{
		if((*this).IsEmpty())
			cout<<"Queue is empty!"<<endl;
		if(!out.IsEmpty())
		{
			ElemType e;
			out.Pop(e);
			cout<<"DelQueue "<<e<<endl;
		}
		else
		{
			while(!(in.IsEmpty()))
			{
				ElemType e;
				in.Pop(e);
				out.Push(e);
			}
			ElemType e;
			out.Pop(e);
			cout<<"DelQueue "<<e<<endl;
		}
	}
};
int main(void)
{
	BadQueue<int> bq;
	bq.EnQueue(1);
	bq.EnQueue(2);
	bq.EnQueue(3);
	bq.EnQueue(4);
	bq.DelQueue();
	bq.DelQueue();
	bq.EnQueue(5);
	bq.DelQueue();
	bq.DelQueue();
	bq.DelQueue();
	return 0;
}

