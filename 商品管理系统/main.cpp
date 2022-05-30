#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "SeqList.cpp"
#include "Goods.h"
using namespace std;

int menu()
{
	int choice;
	cout<<"----------------------------"<<endl;
	cout<<"-       ������ϵͳ       -"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"-      1.��ʾ���          -"<<endl;
    cout<<"-      2.�޸Ŀ��          -"<<endl;
    cout<<"-      3.ɾ����¼		  -"<<endl;
    cout<<"-      4.�Կ���¼����    -"<<endl;
    cout<<"-      5.�˳�       -"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"��ѡ�������";
	cin>>choice;
	return choice;
}

int main()
{
	ifstream in("data.txt");
	Goods goods[100];
	Goods del;
	int count = 0;
	while (!in.eof())
	{
		in>>goods[count];
		count++;
	}
	in.close();
	SeqList <Goods,100> s(goods,count);
	while (true)
	{
		int index,pos;
		Goods g;
		int choice = menu();
		switch(choice)
		{
		case 1:
			cout<<"*************************************************"<<endl;
			cout<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��Ʒ�۸�"<<setw(13)<<"��Ʒ���"<<endl;
			s.Print();
			cout<<"*************************************************"<<endl;
			break;
		case 2:
			cout<<"������Ҫ�޸ĵ���Ʒ����"<<endl;			
			cin>>index;
			g.SetID(index);
			pos = s.Locate(g);
			if (pos == -1)
			{
				cout<<"��ǰ�����Ų����ڣ���ʼ����¼�¼��"<<endl;
				string name;
				float price;
				int stock;
				cout<<"�������Ʒ�����ơ��۸�Ϳ������"<<endl;
				cin>>name>>price>>stock;
				g.SetName(name);
				g.SetPrice(price);
				g.SetStock(stock);
				s.Insert(s.GetLength()+1,g);
				cout<<"*****************************"<<endl;
				cout<<"�޸ĺ�Ŀ��Ϊ��"<<endl;
				cout<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��Ʒ�۸�"<<setw(13)<<"��Ʒ���"<<endl;
				s.Print();
				cout<<"*************************************************"<<endl;
			}
			else
			{
				int restock;
				cout<<"����������������"<<endl;
				cin>>restock;
		 		s.GetData(pos).SetStock(restock);
				cout<<"�޸ĺ�Ŀ��Ϊ��"<<endl;
				cout<<"*************************************************"<<endl;
				cout<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��Ʒ�۸�"<<setw(13)<<"��Ʒ���"<<endl;
				s.Print();
				cout<<"*************************************************"<<endl;
			}
			break;
		case 3:
			cout<<"������Ҫɾ������Ʒ�Ĵ��룺"<<endl;
			cin>>index;
			g.SetID(index);
			pos = s.Locate(g);
			del = s.DeletePosition(pos);
			cout<<"ɾ���ɹ���"<<endl;
			cout<<"��ǰ���Ϊ��"<<endl;
			//cout<<"�޸ĺ�Ŀ��Ϊ��"<<endl;
			cout<<"*************************************************"<<endl;
			cout<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��Ʒ�۸�"<<setw(13)<<"��Ʒ���"<<endl;
			s.Print();
			cout<<"*************************************************"<<endl;
			break;
		case 4:
			s.Sort();
			cout<<"�����Ŀ���Ϊ��"<<endl;
			cout<<"*************************************************"<<endl;
			cout<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��Ʒ�۸�"<<setw(13)<<"��Ʒ���"<<endl;
			s.Print();
			cout<<"*************************************************"<<endl;
			break;
		case 5:
			return 0;
		default:
			cout<<"��������룬����ѡ"<<endl;
		}
	}
	return 0;
}