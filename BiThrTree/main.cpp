#include <iostream>
#include <vector>
#include "BiThrTree.h"
using namespace std;
int main()
{
	cout<<"���������ݣ�"<<endl;
	char c;
	vector<char> data;
	while (cin>>c)
	{
		if (c!='@')
			data.push_back(c);
		else
			break;
	}
	InBiThrTree<char> t(data);
	t.InThreaded();
	cout<<"�������������������Ϊ:"<<endl;
	t.Travese();
	cout<<endl;
	cout<<"B�ĺ�̽���ַΪ��"<<endl;
	BiThrNode<char> *p = t.GetRoot();
	p = p->lchild;
	cout<<t.GetNext(p)<<endl;
	cout<<"B��ǰ������ַΪ��"<<endl;
	cout<<t.GetPrev(p)<<endl;
	cout<<"B�ĸ�����ַΪ��"<<endl;
	cout<<t.GetParent(p)<<endl;
	return 0;
}