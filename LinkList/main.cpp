#include <iostream>
#include "linklist.cpp"

using namespace std;

int main()
{
	int a[5]={1,2,3,4,5};
	LinkList<int> s(a,5);
	cout<<"ԭʼ������Ϊ��"<<endl;
	s.PrintLinkList();

	cout<<"����ĳ���Ϊ��"<<s.ListLength()<<endl;

	cout<<"����ڶ���Ԫ��Ϊ��"<<s.Get(2)<<endl;

	cout<<"��������ֵ3�ڵ�"<<s.Locate(3)<<"��Ԫ��"<<endl;

	s.Insert(2,3);
	cout<<"������ĵڶ���λ�ò���3�������Ϊ��"<<endl;
	s.PrintLinkList();

	s.Delete(3);
	cout<<"ɾ�����������ݺ������Ϊ��"<<endl;
	s.PrintLinkList();

	s.Invert();
	cout<<"ת�ú������Ϊ��"<<endl;
	s.PrintLinkList();

	cout<<"�������к������Ϊ��"<<endl;
	int b[5]={0,2,5,6,7};
	LinkList<int> g(b,5);
	g.Invert();
	s.Merge(s,g);
	s.PrintLinkList();
	s.~LinkList();
	return 0;
}