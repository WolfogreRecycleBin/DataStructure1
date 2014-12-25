//int Main.cpp
#include "SeqStack.h"
class badqueue
{

	SeqStack<int> in;
	SeqStack<int> out;
public:
	badqueue()
	{}
	bool IsEmpty()
	{
		if(in.IsEmpty() && out.IsEmpty())
			return true;
		return false;
	}
	void EnQueue(int e)
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
			int e;
			out.Pop(e);
			cout<<"DelQueue "<<e<<endl;
		}
		else
		{
			while(!(in.IsEmpty()))
			{
				int e;
				in.Pop(e);
				out.Push(e);
			}
			int e;
			out.Pop(e);
			cout<<"DelQueue "<<e<<endl;
		}
	}
	

};
int main(void)
{
	badqueue bq;
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

