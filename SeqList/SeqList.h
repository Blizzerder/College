#ifndef SEQLIST_H
#define SEQLIST_H

template <class T, int MAXSIZE>

class SeqList 
{
private:
	T data[MAXSIZE];
	int length;
public:
	SeqList();
	SeqList(T a[],int max);		
	int GetLength();			//
	T GetData(int t);			//
	int GetPosition(T eg,T *b);	//		
	void Print();				//
	void Insert(int i, T data);	//
	T DeletePosition(int i);	//
	void Sort();				//
/**********************
//��չ�÷�
**************************/
	void Merge(SeqList &L);		//����ϲ�˳���*
	T DeleteMin();				//��˳�����ɾ��������Сֵ��Ԫ�ز�������Сֵ���ճ���λ�������һ��ֵ�
	void DeleteItem(T item);	//��˳�����ɾ�����и���ֵitem������Ԫ��*
	void DeleteItem(T s,T t);	//������˳�����ɾ��ֵ��s~t֮�������Ԫ��*
	void DeleteRepeat();		//ɾ��һ��˳����������ظ���Ԫ�أ�ʹ����Ԫ�ص�ֵ������ͬ*
	void ReSortList();			//��������˳���ʹ����a1Ϊ���ߣ�ǰ���a1С�������a1��
	void MoveLeft(int p);
	void Switch(int l,int r);
};

#endif