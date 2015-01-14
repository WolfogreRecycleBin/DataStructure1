#include "Heap.h"
#include <sstream>
#include <string>
int main()
{
	int a[1000],n,size=0;
	string str;
	stringstream sstr;
	cout<<"请输入用于构造堆的整数元素:"<<endl;
	getline(cin,str);
	sstr<<str;
	while(sstr>>n)
	{
		a[size++]=n;
	}
	Heap<int> ha(a,size*2,size);
	int e;
	char c = 'x'; 
	cout<<endl;
	ha.Traverse(Write<int>);
	cout << endl << endl;	

    while (c != '0')	{
        cout << endl << "1. 插入元素.";
        cout << endl << "2. 删除堆顶元素.";
        cout << endl << "3. 显示堆.";
        cout << endl << "4. 重设堆的类型.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "输入插入元素的值:";
			    cin >> e;
				ha.Insert(e);
			    break;
           	case '2':
				ha.DeleteTop(e);
				cout<<"删除的堆顶元素为:"<<e<<endl;
			    break;
		    case '3':
				cout << endl;
				ha.Traverse(Write<int>);
				break;
			case '4':
				cout << endl;
				ha.SetType();
				ha.Traverse(Write<int>);
				break;
		}
	}

	
	system("pause");
	return 0;
}
