#include "TriSparseMatrix.h"		// ϡ��������Ԫ��˳���

int main(void)
{
	
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int rs = 7, cs = 6;
		TriSparseMatrix<int> a(rs, cs),b(rs, cs),c(rs, cs);
		int m[rs][cs] = {
			15,	 0,	 0,	22,	 0, -5, 
			 0,	11,	 3,	 0,	 0,  0, 
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
		    91,	 0,	 0,	 0,	 0,  0,
             0,  7,  0,  0,  0,  0,
             0,  0, 28,  0,  0,  0
		};
		int n[rs][cs]={
			13,	 0,	 0,	22,	 0, 0, 
			 0,	33,	 3,	 0,	 0,  0, 
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  -5,
		    0,	 0,	 0,	 0,	 0,  0,
             0,  -7,  0,  0,  0,  0,
             30,  0, 10,  0,  0,  0
		};
		int i, j, v;					// ��ʱ����	

		// ����ϡ�����a��Ԫ��ֵ
		for (i = 0; i < rs; i++) 
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// ����Ԫ��ֵ
		for (i = 0; i < rs; i++) 
			for (j = 0; j < cs; j++)
				b.SetElem(i, j, n[i][j]);	// ����Ԫ��ֵ
		// ��ʾϡ�����a
		cout << "����a:" << endl;
		for (i = 0; i < a.GetRows(); i++)	{	
			for (j = 0; j < a.GetCols(); j++)	{	
				a.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << "����b:" << endl;
		for (i = 0; i < b.GetRows(); i++)	{	
			for (j = 0; j < b.GetCols(); j++)	{	
				b.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << "����a+b:" << endl;
		c=a+b;
		for (i = 0; i < c.GetRows(); i++)	{	
			for (j = 0; j < c.GetCols(); j++)	{	
				c.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
    }
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


