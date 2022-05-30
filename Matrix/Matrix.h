#ifndef MATRIX_H_
#define MATRIX_H_
#include<vector>
template<class T>
struct Triple						//������Ԫ�صĳ�Ա�ṹ
{
	int r,c;						//�����ꡢ������
	T elem;							//Ԫ��ֵ
};

template<class T>  
class SparseMatrix	
{	
	vector< Triple<T> >triList;    //����ԪΪԪ�ع�������
	int rows,cols,num;				//����������������
public:
	SparseMatrix();					//�޲ι��캯��
	SparseMatrix(Triple<T> * tlist, int rs , int cs ,int n);		//�вι��캯��
	void Trans1(SparseMatrix &B);
	void Trans2(SparseMatrix &B);
	SparseMatrix& plus(SparseMatrix &B);
	SparseMatrix& mult(SparseMatrix &B);
	void print();
};
