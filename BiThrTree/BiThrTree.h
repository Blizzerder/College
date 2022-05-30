#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum BiThrNodeType{LINK,THREAD};

template<class T>
struct BiThrNode
{
	BiThrNodeType ltype,rtype;
	T data;
	BiThrNode<T> *lchild,*rchild;
};
//template<class T>
BiThrNode<char> * prenode;
//template <class T>


template <class T>
class InBiThrTree				//��������������
{
private:
	BiThrNode<T> * root;
	BiThrNode<T> * CreateByPre(vector<T> &pre , int &i)
	{
		T e = pre[i];
		i++;
		if (e == '*')
			return NULL;
		BiThrNode<T>* p = new BiThrNode<T>;
		p->data = e;
		p->ltype = LINK;
		p->rtype = LINK;
		p->lchild = CreateByPre(pre,i);
		p->rchild = CreateByPre(pre,i);
		return p;
	}
	
	void InThreaded(BiThrNode <T> * &p)
	{
		if (p==NULL)
			return;
		InThreaded(p->lchild);
		if (p->lchild == NULL)
		{
			p->ltype = THREAD;
			p->lchild = prenode;
		}
		if (p->rchild == NULL)
			p->rtype = THREAD;
		if (prenode != NULL)
		{
			if (prenode->rtype == THREAD)
				prenode->rchild = p;
		}
		prenode = p;
		InThreaded(p->rchild);
		}
	void Free(BiThrNode<T>*p);
public:
	
	BiThrNode<T> * GetRoot()
	{
		return root;
	}
	InBiThrTree(){root = NULL;}
	InBiThrTree(vector<T> &pre)
	{
		int i = 0;
		root = CreateByPre(pre , i);
	}
	//�������д���������
	void InThreaded()
	{
		InThreaded(root);
	}
	//����������
//	~InBiThrTree();							   //��������
	BiThrNode<T> * GetNext(BiThrNode<T> * p) 
	{
		if(p->rtype == THREAD)
			return p->rchild;
		p = p->rchild;
		while (p->ltype == LINK)
			p = p->lchild;
		return p;
	}//���̽��
	BiThrNode<T> * GetPrev(BiThrNode<T> * p)
		{
	if (p->ltype == THREAD)
		return p->lchild;
	p = p->lchild;
	while (p->rtype == LINK)
		p = p->rchild;
	return p;
}//��ǰ�����
	void Travese()	
	{
		BiThrNode<T>* p = root;
		while (p->ltype == LINK)
			p = p->lchild;
		while (p!= NULL)
		{
			cout<<p->data<<" ";
			p = GetNext(p);
		}
	}//�������������������
	BiThrNode<T> * GetParent(BiThrNode<T> * p)
	{
	if (p == NULL)
		return NULL;
	BiThrNode<T> *parent;
	parent = p;
	while (parent->rtype == LINK)
		parent = parent->rchild;
	parent = parent->rchild;
	if (parent&&parent->lchild==p)
		return parent;
	parent = p;
	while (parent->ltype == LINK)
		parent = parent->lchild;
	parent = parent->lchild;
	return parent;
}
//�󸸽ڵ��ַ
};



#endif