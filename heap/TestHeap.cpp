#include "Heap.h"
#include <sstream>
#include <string>
int main()
{
	int a[1000],n,size=0;
	string str;
	stringstream sstr;
	cout<<"���������ڹ���ѵ�����Ԫ��:"<<endl;
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
        cout << endl << "1. ����Ԫ��.";
        cout << endl << "2. ɾ���Ѷ�Ԫ��.";
        cout << endl << "3. ��ʾ��.";
        cout << endl << "4. ����ѵ�����.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "�������Ԫ�ص�ֵ:";
			    cin >> e;
				ha.Insert(e);
			    break;
           	case '2':
				ha.DeleteTop(e);
				cout<<"ɾ���ĶѶ�Ԫ��Ϊ:"<<e<<endl;
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
