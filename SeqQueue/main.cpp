#include <iostream>
#include "SeqQueue.cpp"

using namespace std;

int main()
{
	SeqQueue<int , 3> s;
	s.EnQueue(1);							//1
	cout<<"����1֮���ͷԪ��Ϊ��";
	cout<<s.GetQueue()<<endl;				
	s.EnQueue(2);							//2  1
	cout<<"����2֮���ͷԪ��Ϊ��";
	cout<<s.GetQueue()<<endl;

	//cout<<s.Full()<<endl;
	s.EnQueue(3);
	cout<<"����3֮����������Ϊ��";
	cout<<s.Full()<<endl;
	cout<<"ɾ��2֮���ͷԪ��Ϊ��";
	s.DeQueue();							//2
	cout<<s.GetQueue()<<endl;
	s.DeQueue();
	s.DeQueue();
	cout<<"��ɾ������֮����пս��Ϊ��";
	cout<<s.Empty()<<endl;
	return 0;
}
