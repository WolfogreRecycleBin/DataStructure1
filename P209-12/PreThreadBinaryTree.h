#ifndef __IN_THREAD_BINARY_TREE_H__
#define __IN_THREAD_BINARY_TREE_H__

#include "BinaryTree.h"			// 二叉链表类
#include "ThreadBinTreeNode.h"	// 线索二叉链表结点类

// 先序线索二叉树类
template <class ElemType>
class PreThreadBinTree
{
protected:
//  线索二叉树的数据成员:
	ThreadBinTreeNode<ElemType> *root;

//	辅助函数:
	void PreThreadHelp(ThreadBinTreeNode<ElemType> *p, ThreadBinTreeNode<ElemType> *&pre);
		// 先序线索化以p为根的二叉树,pre为p中第一个结点的前驱结点指针。 
	ThreadBinTreeNode<ElemType> *TransformHelp(BinTreeNode<ElemType> *r);
		// 将以r为根的二叉树转换成新的未线索化的先序线索二叉树,返回新二叉树的根
	ThreadBinTreeNode<ElemType> *CopyTreeHelp(ThreadBinTreeNode<ElemType> *t);	
		// 复制线索二叉树
	void DestroyHelp(ThreadBinTreeNode<ElemType> * &r);		// 销毁以r为根二叉树
	ThreadBinTreeNode<ElemType> *GetPre(ThreadBinTreeNode<ElemType> *r) const
	{
		ThreadBinTreeNode<ElemType> *p,*pre=NULL;	// 从根开始遍历
		for (p = GetFirst(); p != NULL; p = GetNext(p))	{
			if(p==r) return pre;
			pre=p;
		}
		return NULL;
	}

public:
//  线索二叉树方法成员:
	PreThreadBinTree(const BinaryTree<ElemType> &bt);		
		// 由二叉树构造先序线索二叉树——转换构造函数
	virtual ~PreThreadBinTree();								// 析构函数
	ThreadBinTreeNode<ElemType> *GetRoot() const;			// 返回线索二叉树的根
	void PreThread();										// 先序线索化二叉树
	ThreadBinTreeNode<ElemType> *GetFirst() const;
	ThreadBinTreeNode<ElemType> *GetLast() const;
	ThreadBinTreeNode<ElemType> *GetNext(ThreadBinTreeNode<ElemType> *p) const;	
		// 取指定结点p在先序序列中下一个结点 
	ThreadBinTreeNode<ElemType> *Find(const ElemType &e) const; // 查找元素e 
	void InsertRightChild(ThreadBinTreeNode<ElemType> *p, const ElemType &e);// 插入右孩子
	void DeleteLeftChild(ThreadBinTreeNode<ElemType> *p);   // 删除p的左子树 

	void PreOrder(void (*Visit)(const ElemType &)) const;	// 二叉树的先序遍历	
	PreThreadBinTree(const PreThreadBinTree<ElemType> &t);	// 复制构造函数
	PreThreadBinTree<ElemType> &operator=(const PreThreadBinTree<ElemType>& t);
		// 赋值运算符重载
};

template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinTreeNode<ElemType> *r, int level);
	//	按树状形式显示以r为根的线索二叉树，level为层次数，可设根结点的层次数为1
template <class ElemType>
void DisplayBTWithTreeShape(PreThreadBinTree<ElemType> &bt);
	//	树状形式显示线索二叉树 


// 二叉树类的实现部分
template <class ElemType>
void PreThreadBinTree<ElemType>::PreThreadHelp(ThreadBinTreeNode<ElemType> *p, 
	ThreadBinTreeNode<ElemType> *&pre)
//////////////////////////////////////////////////////////////////////////////////////////////////更改！
// 操作结果：先序线索化以p为根的二叉树,pre为p中第一个结点的前驱结点指针 
{
	if (p != NULL)	{
		if(p->leftChild == NULL)	{	// p无左孩子,加前驱线索 
			p->leftChild = pre;			// p的前驱为pre
			p->leftTag = 1;			    // 左标志为线索
		}
		else	                       // p有左孩子, 左标志为孩子 
			p->leftTag = 0;	
		
		if(pre != NULL && pre->rightChild == NULL)	{	// pre无右孩子, 加线索
			pre->rightChild = p;		// pre后继为p
			pre->rightTag = 1;			// 右标志为线索 
  		}
  		else if (pre != NULL)	        // p有右孩子, 右标志为孩子 
			pre->rightTag = 0;

		pre = p;						// 遍历下一结点时,p为下一结点的前驱

		if(p->leftTag == 0) PreThreadHelp(p->leftChild, pre);// 线索化p的左子树
		if(p->rightTag == 0) PreThreadHelp(p->rightChild, pre);// 线索化p的右子树
	}
}

template <class ElemType>
void PreThreadBinTree<ElemType>::PreThread()
// 操作结果：先序线索化二叉树
{
	ThreadBinTreeNode<ElemType> *pre = NULL;	// 先序序列中第一个结点的前驱为空
	PreThreadHelp(root, pre);					// 先序线索化以root为根的二叉树
	pre->rightTag = 1;				            // 先序中最后一个的右指针为线索
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::TransformHelp(BinTreeNode<ElemType> *r)
// 操作结果：r为根的二叉树转换成新的未线索化的先序线索二叉树,返回新二叉树的根
{
	if (r == NULL)	// 空二叉树转换成新的空线索二叉树
		return NULL;							// 空线索二叉树根为空	
	else  {	// 转换非空二叉树
		ThreadBinTreeNode<ElemType> *lChild = TransformHelp(r->leftChild);	// 转换左子树
		ThreadBinTreeNode<ElemType> *rChild = TransformHelp(r->rightChild);	// 转换右子树
		ThreadBinTreeNode<ElemType> *rt = new ThreadBinTreeNode<ElemType>(r->data, lChild, rChild);
			// 转换根结点
		return rt;															// 返回根结点
	}
}

template <class ElemType>
PreThreadBinTree<ElemType>::PreThreadBinTree(const BinaryTree<ElemType> &bt)
// 操作结果：由二叉树构造先序线索二叉树——转换构造函数
{
	root = TransformHelp(bt.GetRoot());			// 转换成未线索化的二叉树
	PreThread();									// 线索化二叉树
}

template <class ElemType>
void PreThreadBinTree<ElemType>::DestroyHelp(ThreadBinTreeNode<ElemType> * &r)
// 操作结果：销毁以r为根的线索二叉树
{
	if(r != NULL)	{	// r非空,实施销毁
		if (r->leftTag == 0) DestroyHelp(r->leftChild);		// 销毁左子树
		if (r->rightTag == 0) DestroyHelp(r->rightChild);	// 销毁右子树
		delete r;											// 销毁根结点
		r = NULL;					
	}
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::GetNext(ThreadBinTreeNode<ElemType> *p) const
// 操作结果：返回先序序列中p的后继结点
{	
    if (p->leftTag == 0)	    // 右指针为线索，后继为p->rightChild
        return p->leftChild;
	return p->rightChild;		// p指向其右孩子	
}


template <class ElemType>
PreThreadBinTree<ElemType>::~PreThreadBinTree()
// 操作结果：销毁线索二叉树--析构函数
{
	DestroyHelp(root);
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::GetRoot() const
// 操作结果：返回线索二叉树的根
{	
	return root;
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::GetFirst() const
// 操作结果：返回线索二叉树先序序列的第一个结点
{	
	return root;        
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::GetLast() const
// 操作结果：返回线索二叉树先序序列的最后一个结点
{	
	if (root ==  NULL)
       return  NULL;
    else {
       ThreadBinTreeNode<ElemType> *p = root;
	   while (p->rightTag == 0)
			p = p->rightChild;	
	   return p;
    }         
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::Find(const ElemType &e) const
// 操作结果：查找元素e,查找成功返回其指针，否则返回NULL. 
{	
	ThreadBinTreeNode<ElemType> *p = GetFirst();	// 从根开始遍历
	while (p != NULL && p->data != e)
		p = GetNext(p);
	return p;
}

template <class ElemType>
void PreThreadBinTree<ElemType>::InsertRightChild(ThreadBinTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的右孩子，如果p的右孩子非空，则p原有右子树成为e的右子树
{
	ThreadBinTreeNode<ElemType> *x, *q; 
  	if (p == NULL)	                // p空，返回
		return;
	else 	{
		q=p;
		if (p->leftTag == 0)	{ 
           q = p->leftChild;
           while (q->rightTag == 0 || q->leftTag == 0)
		   {
               if(q->rightTag == 0) q = q->rightChild;
			   if(q->leftTag == 0) q = q->leftChild;
		   }
        }
		x =  new ThreadBinTreeNode<ElemType>(e, q, q->rightChild, 1, p->rightTag);
		q->rightChild = x;
		if(x->rightChild->leftTag==1) x->rightChild->leftChild=x;
        p->rightChild = x;
        p->rightTag = 0;      
		return;
	}
}

template <class ElemType>
void PreThreadBinTree<ElemType>::DeleteLeftChild(ThreadBinTreeNode<ElemType> *p)
// 初始条件：p非空，
// 操作结果：删除p的左子树
{
	/*ThreadBinTreeNode<ElemType>*q; 
  	if (p == NULL || p->leftTag != 0)	// p空，返回
		return;
	else 	{	
		q = p->leftChild;
        while (q->leftTag == 0)
           q = q->leftChild;
        q = q->leftChild;
        DestroyHelp(p->leftChild);
        p->leftChild = q;
        p->leftTag = 1;      
		return;
	}*/
	//求左子树最后一个节点
	ThreadBinTreeNode<ElemType>*q; 
  	if (p == NULL || p->leftTag != 0)	// p空，返回
		return;
	q = p->leftChild;
	while (q->rightTag == 0 || q->leftTag == 0)
	{
		if(q->rightTag == 0) q = q->rightChild;
		if(q->leftTag == 0) q = q->leftChild;
	}
	if(p->rightTag==1) p->rightChild=q->rightChild;
	if(q->rightChild->leftTag==1) q->rightChild->leftChild=p;
	DestroyHelp(p->leftChild);
	p->leftTag=1;
	p->leftChild=GetPre(p);
}

template <class ElemType>
void PreThreadBinTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
// 操作结果：二叉树的先序遍历	
{
	ThreadBinTreeNode<ElemType> *p;	// 从根开始遍历
	for (p = GetFirst(); p != NULL; p = GetNext(p))	{		// 查找最左侧的结点，此结 
		(*Visit)(p->data);					// 访问当前结点
		if (p->leftTag == 1)
		    cout << "其左指针为线索指针，指向";
        else 
		    cout << "其左指针为孩子指针，指向";
        if (p->leftChild != NULL)
 		    cout << p->leftChild->data ; 
        else
 		    cout << "NULL" ; 
		if (p->rightTag == 1)
		    cout << "；其右指针为线索指针，指向";
        else 
		    cout << "；其右指针为孩子指针，指向";
        if (p->rightChild != NULL)
 		    cout << p->rightChild->data << endl; 
        else
 		    cout << "NULL" << endl; 
     }
}

template <class ElemType>
ThreadBinTreeNode<ElemType> *PreThreadBinTree<ElemType>::CopyTreeHelp(ThreadBinTreeNode<ElemType> *t)	
// 操作结果：将以t为根的线索二叉树复制成新的未线索化的二叉树,返回新二叉树的根
{
	if (t == NULL)	// 复制空线索二叉树
		return NULL;								// 空线索二叉树根为空	
	else	{	// 复制非空线索二叉树
		ThreadBinTreeNode<ElemType> *lChild;
		ThreadBinTreeNode<ElemType> *rChild;
		if (t->leftTag == 0)
			lChild = CopyTreeHelp(t->leftChild);	// 复制左子树
		else
            lChild = NULL;							// 左子树为空
		if (t->rightTag == 0)
			rChild = CopyTreeHelp(t->rightChild);// 复制右子树
		else
            rChild = NULL;							// 左子树为空
		ThreadBinTreeNode<ElemType> *r = new ThreadBinTreeNode<ElemType>(t->data, lChild, rChild);
			// 复制根结点
		return r;
	}
}

template <class ElemType>
PreThreadBinTree<ElemType>::PreThreadBinTree(const PreThreadBinTree<ElemType> &t)
// 操作结果：由已知线索二叉树构造新线索二叉树——复制构造函数
{
	root = CopyTreeHelp(t.root);					// 复制线索二叉树
	PreThread();										// 先序线索化二叉树
}

template <class ElemType>
PreThreadBinTree<ElemType> &PreThreadBinTree<ElemType>::operator=(const PreThreadBinTree<ElemType> &t)
// 操作结果：由已知线索二叉树t复制到当前线索二叉树--赋值运算符重载
{
	if (&t != this)	{
		DestroyHelp(root);							// 释放原线索二叉树所占用空间
		root = CopyTreeHelp(t.root);				// 复制线索二叉树
		PreThread();									// 先序线索化二叉树
	}
	return *this;
}

template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinTreeNode<ElemType> *r, int level)
//	操作结果：按树状形式显示以r为根的线索二叉树，level为层次数，可设根结点的层次数为1
{
	if(r != NULL)	{	//空树不显式，只显式非空树
		if (r->rightTag == 0)
			DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild, level + 1);//显示右子树
		cout << endl;								//显示新行	
		for(int i = 0; i < level - 1; i++)
			cout << "  ";							//确保在第level列显示结点
		cout << r->data;							//显示结点
		if (r->leftTag == 0)
			DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild, level + 1);//显示左子树
	}
}

template <class ElemType>
void DisplayBTWithTreeShape(PreThreadBinTree<ElemType> &bt)
//	操作结果：树状形式显示线索二叉树 
{
	DisplayBTWithTreeShapeHelp<ElemType>(bt.GetRoot(), 1);	
		// 树状显示以bt.GetRoot()为根的线索二叉树
	cout << endl;
}

#endif
