#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};

template <class T>
class BiTree
{
private:
	BiNode<T> * root;   // ��ָ��
	void PreOrder(BiNode<T>*p);
	void InOrder(BiNode<T>*p);
	void PostOrder(BiNode<T>*p);
	BiNode<T>* CreateByPre(vector<T> &pre, int &i);
	BiNode<T>* CreateByPreMid(vector<T> &pre , vector<T> &mid ,int ipre , int imid ,int n);
	BiNode<T>* Copy(BiNode<T> *p);
	void Free(BiNode<T>* p);
	int Count(BiNode<T>*p);
	int Height(BiNode<T>*p);
	BiNode<T>* Search(BiNode<T>* p,T e);
	BiNode<T>* SearchParent(BiNode<T>* p,BiNode<T>* child);
public:
	BiTree() { root = NULL; }				//�޲ι��캯�����������
	BiTree(vector<T> &pre);					//�������й��������
	BiTree(vector<T> &pre,vector<T> &mid);	//���������������
	BiTree(BiTree<T> &tree);				//�������캯��
	~BiTree();								//��������
	void PreOrder();						//�������
	void InOrder();							//�������
	void PostOrder();						//�������
	void LevelOrder();						//�������
	int Count();							//ͳ�ƽ�����
	int Height();							//����������ĸ߶�
	BiNode<T> *Search(T e);					//����ֵe���ҽ��
	BiNode<T> *SearchParent(BiNode<T>* child);//����ָ���ڵ�ĸ��ڵ�
};

#endif