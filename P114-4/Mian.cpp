//Main.cpp
#include "SeqStack.h"
int main(void)
{
	cout<<"�½�"<<endl;
	SeqStack<int> ss(10);
	ss.Show();
	
	cout<<"ǰѹջ"<<endl;
	ss.Push(1,1);
	ss.Show();
	
	cout<<"��ѹջ"<<endl;
	ss.Push(2,2);
	ss.Show();
	
	cout<<"��ѹջ"<<endl;
	ss.Push(3,2);
	ss.Show();
	
	int e;
	cout<<"ǰ��ջ"<<endl;
	ss.Pop(e,1);
	ss.Show();
	
	cout<<"���ջ"<<endl;
	ss.Pop(e,2);
	ss.Show();
	
	return 0;
}
