#include <iostream>
#include <vector>
#include "tree.cpp"
using namespace std;

int main()
{
	//cout<<"����������ǰ��ֵ��"<<endl;
	vector<char> data1;
	vector<char> data2;
	char c;
	while (cin>>c)
	{
		if (c!='@')
			data1.push_back(c);
		else
			break;
	}
	
	while (cin>>c)
	{
		if (c!='@')
			data2.push_back(c);
		else
			break;
	}
	BiTree<char> t(data1,data2);
	cout<<"����ǰ�����Ϊ��";t.PreOrder();
	cout<<endl<<"�����������Ϊ��";t.InOrder();
	cout<<endl<<"���ĺ������Ϊ��";t.PostOrder();
	cout<<endl;
	cout<<"���Ĳ������Ϊ��";t.LevelOrder();
	cout<<endl;
	cout<<"���Ľ�����Ϊ��"<<t.Count()<<endl;
	cout<<"���ĸ�Ϊ��"<<t.Height()<<endl;
	cout<<"ָ��A��ָ��Ϊ��"<<t.Search('A')<<endl;
	return 0;
}