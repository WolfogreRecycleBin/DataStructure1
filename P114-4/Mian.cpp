//Main.cpp
#include "SeqStack.h"
int main(void)
{
	cout<<"新建"<<endl;
	SeqStack<int> ss(10);
	ss.Show();
	
	cout<<"前压栈"<<endl;
	ss.Push(1,1);
	ss.Show();
	
	cout<<"后压栈"<<endl;
	ss.Push(2,2);
	ss.Show();
	
	cout<<"后压栈"<<endl;
	ss.Push(3,2);
	ss.Show();
	
	int e;
	cout<<"前出栈"<<endl;
	ss.Pop(e,1);
	ss.Show();
	
	cout<<"后出栈"<<endl;
	ss.Pop(e,2);
	ss.Show();
	
	return 0;
}
