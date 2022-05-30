#include <iostream>
#include "SeqList.cpp"

using namespace std;

void main()
{
	int a[5];
	cout<<"������5��ԭʼ���ݣ�"<<endl;
	for (int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	SeqList<int , 100> s(a,5);
	cout<<"ԭʼ˳�����ʾΪ�� ";
	s.Print();
	s.Insert(2,7);
	cout<<"������˳�����ʾΪ�� ";
	s.Print();
	s.DeletePosition(2);
	cout<<"ɾ�����˳�����ʾΪ�� ";
	s.Print();

	/****************
	��չ����
	****************/

	s.Sort();
	cout<<"������˳�����ʾΪ�� ";
	s.Print();

	cout<<"����������õ�������λ�ã� ";
	int k;
	cin>>k;
	cout<<"��λ�õ�����Ϊ";
	cout<<s.GetData(k)<<endl;

	cout<<"�������������λ�õ����ݣ� ";
	int h;
	cin>>h;
	int ss[100];
	int aa = s.GetPosition(h,ss);
	if (aa != 0)
	{
		cout<<"�������ڵ�";
		for (i=0;i<aa;i++)
			cout<<ss[i]+1<<" ";
		cout<<"��λ��"<<endl;
	}
	else
		cout<<"�޸���ֵ��"<<endl;

	int b[4]={4,1,3,5};
	SeqList<int,100> p(b,4);
	s.Merge(p);
	cout<<"���������˳�����ʾΪ�� ";
	s.Print();

	cout<<"ɾ������СֵΪ�� ";
	cout<<s.DeleteMin()<<endl;

	s.DeleteItem(3);
	cout<<"ɾ�����е�3���˳�����ʾΪ�� ";
	s.Print();

	s.DeleteItem(2,4);
	cout<<"ɾ��2~4���˳�����ʾΪ�� ";
	s.Print();

	s.DeleteRepeat();
	cout<<"ȥ�غ��˳�����ʾΪ�� ";
	s.Print();

	int c[6]={5,1,3,7,8,2};
	SeqList<int,100> f(c,6);
	f.ReSortList();
	cout<<"�������е�˳�����ʾΪ�� ";
	f.Print();

	f.MoveLeft(2);
	cout<<"����2λ���˳�����ʾΪ�� ";
	f.Print();
}