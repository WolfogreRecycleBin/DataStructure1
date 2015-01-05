#include "SqBinaryTree.h"				// ˳��洢��������

int main(void)
{
	int p;
	char c='a', e;

	char pre[]={'A','B','D','E','G','H','C','F','I'};		// ��������
	char in[]={'D','B','G','E','H','A','C','F','I'};		// ��������
	int n = 9, size=15;										// ������
	SqBinaryTree<char> bt;
	bt = CreateBinaryTree(pre, in, n, size);				// ���������
		
	cout << "������A,B,D,E,G,H,C,F,I������D,B,G,E,H,A,C,F,I����Ķ�����:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. ��������.";
        cout << endl << "2. ɾ��������.";
        cout << endl << "3. ��α���";
        cout << endl << "4. �������.";
        cout << endl << "5. �������.";
        cout << endl << "6. �������.";
        cout << endl << "7. ��������Ľ����.";
        cout << endl << "8. ��������ĸ߶�.";
        cout << endl << "9. ��ʾ����������.";
		cout << endl << "a. �������Ԫ�ص������ͬ����.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == -1)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else {
            		cout << endl << "�������Ԫ�ص�ֵ:";
			    	cin >> e;
					bt.InsertLeftChild(p, e);	// ��������
			    }
			    break;
           	case '2':
            	cout << endl << "����ɾ������˫��Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == -1)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else 
					bt.DeleteRightChild(p);					
			    break;
		    case '3':
				cout << endl;
				bt.LevelOrder(Write<char>);
				break;
	         case '4':
				cout << endl;
				bt.PreOrder(Write<char>);
				break;
	         case '5':
				cout << endl;
				bt.InOrder(Write<char>);
				break;
	         case '6':
				cout << endl;
				bt.PostOrder(Write<char>);
				break;
	         case '7':
				cout << endl;
				cout << "�������Ľ����Ϊ��" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "�������ĸ߶�Ϊ��" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
			 case 'a':
				cout<<"����������Ԫ��:"<<endl;
				char a,b,s;
				cin>>a>>b;
				if(bt.FindCommonAncestor(a,b,s)) cout<<"Ԫ�� "<<a<<" ��Ԫ�� "<<b<<" �������ͬ����Ϊ "<<s<<endl;
				break;
		}
	}
	
	system("PAUSE");
	return 0;
}
