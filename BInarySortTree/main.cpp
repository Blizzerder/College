#include <iostream>
#include "BiSortTree.cpp"

using namespace std;

int main()
{
	int a[11]={63,45,90,24,58,74,99,16,35,64,85};
	int n = 11;
	BiSortTree t(a,n);
	cout<<"�����������Ϊ��"<<endl;
	t.InOrder();
	cout<<endl;
	int k = 58;
	bool p1 = t.Search(k);
	if (p1 == 1)
		cout<<"���д��ڽ��"<<k<<endl;
	else
		cout<<"���в����ڽ��"<<k<<endl;
	k = 70;
	bool p2 = t.Search2(k);
	if (p2 == 1)
		cout<<"���д��ڽ��"<<k<<endl;
	else
		cout<<"���в����ڽ��"<<k<<endl;
	cout<<"ɾ��45֮����������Ϊ:"<<endl;
	t.Delete(45);
	t.InOrder();
	return 0;
}