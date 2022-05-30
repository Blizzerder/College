
#include <iostream>
#include <vector>
#include <string>
#include "HuffmanTree.cpp"

using namespace std;
inline unsigned __int64 GetCycleCount()
{
__asm _emit 0x0F
__asm _emit 0x31
}
#define N 500

int main()
{
	vector <HuffmanNode> a;
	HuffmanNode a1;
	char c;
	double w;
	cout<<"������Ԫ��ֵ��"<<endl;
	for (int i = 0;i<N;i++)
	{
		c = rand()%('z'-'a'+1)+'a';
		w = rand()%(10-1+1)+1;
		a1.data = c;
		a1.weight = w;
		a.push_back(a1);
	}
	unsigned long t1,t2;
	t1 = (unsigned long)GetCycleCount();
	HuffmanTree t(a);
	t2 = (unsigned long)GetCycleCount();
	cout<<"�㷨����ʱ��Ϊ��"<<t2-t1<<"ns"<<endl;
	vector<int> num;
	string s;
	for (i =0;i<N;i++)
	{
		num = t.GetCode(i);
		cout<<"��"<<i<<"��Ԫ�صı���Ϊ��";
		for (int j = 0;j<num.size();j++)
			cout<<num[j];
		cout<<endl;
		cout<<"�˱����Ӧ��Ԫ��Ϊ��"<<endl;
		s=t.Decode(num);
		cout<<s<<endl;
	}

	return 0; 
}