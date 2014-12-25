//Main.cpp
#include <iostream>
#include "SeqStack.h"
using namespace std;
void test(int &sum)
{
	int x;
	cin>>x;
	if(x==0) sum=0;
	else
	{
		test(sum);
		sum+=x;
	}
	cout<<sum<<" ";
}
void test2(void)
{
	int x;
	SeqStack<int> data(100);
	while(true)
	{
		cin>>x;
		if(x) data.Push(x);
		else break;
	}
	cout<<x<<' ';
	while(!data.IsEmpty())
	{
		int t;
		data.Pop(t);
		x+=t;
		cout<<x<<' ';
	}
}
int main(void)
{
	int sum=0;
	cout<<"µİ¹é²âÊÔ:"<<endl;
	test(sum);cout<<endl;
	cout<<"·Çµİ¹é²âÊÔ:"<<endl;
	test2();cout<<endl;
	return 0;
}
