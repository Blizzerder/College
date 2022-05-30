#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Triple						//������Ԫ�صĳ�Ա�ṹ
{
	int r;							//������
	int c;							//������						
	T elem;							//Ԫ��ֵ
};
template<class T>  
class SparseMatrix	
{	
	vector< Triple<T> >triList;    //����ԪΪԪ�ع�������
	int rows,cols,num;				//����������������
public:
	SparseMatrix()
	{
		rows = 0;
		cols = 0;
		num = 0;
		triList.resize(0);
	}//�޲ι��캯��
	SparseMatrix(vector< Triple<T> > tlist, int rs , int cs ,int n)
	{
		triList = tlist;
		rows = rs;
		cols = cs;
		num = n;
	}//�вι��캯��
	void Trans1(SparseMatrix<T> &B)
	{
		B.rows = cols;
		B.cols = rows;
		B.num = num;
		B.triList.resize(num);
		if (num == 0)
			return;
		int q = 0;
		for (int col = 0 ; col < cols ; col++)  //��ԭ�������в���
			for (int p = 0 ; p < num ; p++)		
				if (triList[p].c == col)		//ĳһ����Ԫ�ص�����ΪѰ�ҵ���λ
				{
					B.triList[q].r = triList[p].c;
					B.triList[q].c = triList[p].r;
					B.triList[q].elem = triList[p].elem;
					q++;
				}
	}
	void Trans2(SparseMatrix<T> &B)
	{
		B.rows = cols;
		B.cols = rows;
		B.num = num;
		B.triList.resize(num);
		if (num == 0)
			return;
		int cnum[100];
		int cpot[100];
		for(int col=0;col<cols;col++)
			cnum[col]=0;
		for (int i =0 ; i < num ; i++)
		{
			cnum[triList[i].c]++;
		}
		cpot[0] = 0;
		for ( col = 1 ; col < cols ; col++)
			cpot[col] = cpot[col - 1] + cnum[col-1];
		for (int p = 0;p<num;p++)
		{
			col = triList[p].c;
			int q = cpot[col];
			B.triList[q].r = triList[p].c;
			B.triList[q].c = triList[p].r;
			B.triList[q].elem = triList[p].elem;
			cpot[col]++;
		}
//		delete[] cnum;
//		delete[] cpot;
	}

	SparseMatrix& plus(SparseMatrix<T> &B)
	{
		if (rows != B.rows || cols != B.cols)
		{
			cerr<<"����ļ��㣡";
			exit(1);
		}
		int nn = num;
		for (int i = 0; i < B.num ; i++)
		{
			for (int j = 0;j<num;j++)
			if (B.triList[i].r == triList[j].r&&B.triList[i].c == triList[j].c)
			{
				triList[j].elem+=B.triList[i].elem;
				break;
			}
			else
				if ((B.triList[i].r == triList[j].r&&B.triList[i].c<triList[j].c)||(B.triList[i].r < triList[j].r))
				{
					triList.insert(triList.begin()+j,B.triList[i]);
					nn++;
					break;
				}
		}
		num = nn;
		return *this;
	}
	SparseMatrix& mult(SparseMatrix<T> &B);
	void print()
	{
		int n = 0;
		for (int i = 0 ; i < rows ; i++)
		{
			for (int j = 0 ; j < cols ; j++)
			{
				if (triList[n].r == i && triList[n].c == j)
				{
					cout<<triList[n].elem<<" ";
					n++;
				}
				else
					cout<<"0 ";
			}
			cout<<endl;
		}
	}
};
