//Mian.cpp
#include <iostream>
#include "Node.h"
#include "LinkList.h"
#include "Assistance.h"

using namespace std;
int main(void)
{
	int ar[]={1,2,5,8,10},br[]={-10,8,12,56};
	LinkList<int> a(ar,5),b(br,4),c;
	a.Traverse(Write);
	cout<<endl;
	b.Traverse(Write);
	cout<<endl;
	c=Add(a,b);
	c.Traverse(Write);
	cout<<endl;
	return 0;
}
