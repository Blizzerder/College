#ifndef LINKLIST_H
#define LINKLIST_H

template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkList
{
private:
	Node<T> *head;
public:
	LinkList();				//Ĭ�Ϲ��캯��
	LinkList(T a[],int n);	//���ι��캯��
	~LinkList();			//��������
	int ListLength();		//������
	T Get(int pos);			//��λ����
	int Locate(T item);		//��ֵ����
	void PrintLinkList();	//�����ӡ
	void Insert(int i, T item);//����Ĳ���
	T Delete(int i);		//�����ɾ��
	void Invert();			//�����ת��
	void Merge(LinkList &L1,LinkList &L2);
};

#endif