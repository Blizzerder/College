#include <iostream>
#include "SeqStack.cpp"

using namespace std;

int main()
{
	SeqStack<int , 100> s;
	s.Push(1);
	cout<<"�����һ��Ԫ��֮���ջΪ��";
	s.Print();
	s.Push(3);
	s.Push(5);
	cout<<"����ڶ�������Ԫ��֮���ջΪ��";
	s.Print();
	s.Pop();
	cout<<"ɾ��ջ��Ԫ��֮���ջΪ��";
	s.Print();
	cout<<"ջ��Ԫ��Ϊ��"<<s.Top()<<endl;
	return 0;
}