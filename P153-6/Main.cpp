#include "TriSparseMatrix.h"		// 稀疏矩阵的三元组顺序表

int main(void)
{
	
    try								// 用try封装可能出现异常的代码
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
		int i, j, v;					// 临时变量	

		// 设置稀疏矩阵a的元素值
		for (i = 0; i < rs; i++) 
			for (j = 0; j < cs; j++)
				a.SetElem(i, j, m[i][j]);	// 设置元素值
		for (i = 0; i < rs; i++) 
			for (j = 0; j < cs; j++)
				b.SetElem(i, j, n[i][j]);	// 设置元素值
		// 显示稀疏矩阵a
		cout << "矩阵a:" << endl;
		for (i = 0; i < a.GetRows(); i++)	{	
			for (j = 0; j < a.GetCols(); j++)	{	
				a.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << "矩阵b:" << endl;
		for (i = 0; i < b.GetRows(); i++)	{	
			for (j = 0; j < b.GetCols(); j++)	{	
				b.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << "矩阵a+b:" << endl;
		c=a+b;
		for (i = 0; i < c.GetRows(); i++)	{	
			for (j = 0; j < c.GetCols(); j++)	{	
				c.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
    }
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


