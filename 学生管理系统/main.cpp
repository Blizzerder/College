#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "linklist.cpp"
#include "Student.h"
using namespace std;

int menu()
{
	int choice;
	cout<<"    ��ӭʹ��ѧ������ϵͳ��  "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"-      1.��ʾѧ����Ϣ      -"<<endl;
    cout<<"-      2.��ѧ�Ų�ѯ        -"<<endl;
    cout<<"-      3.ɾ��ѧ��		  -"<<endl;
    cout<<"-      4.����ѧ��          -"<<endl;
    cout<<"-      5.�޸�ѧ����Ϣ      -"<<endl;
	cout<<"-      6.�˳�              -"<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"��ѡ�������";
	cin>>choice;
	return choice;
}

int main()
{
	Student student[100];
	int count = 0;
	int index,pos;
	Student g;
	ifstream in("data.txt");
	while (!in.eof())
	{
		in>>student[count];
		count++;
	}
	int id;
			string name;
			char sex;
			string major;
			int year,month,day;
	in.close();
	LinkList <Student> s(student,count);
	while (true)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			cout<<"*************************************************"<<endl;
			cout<<setw(5)<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"�Ա�"<<setw(20)<<"רҵ"<<setw(15)<<"��������"<<endl;
			s.PrintLinkList();
			cout<<"*************************************************"<<endl;
			break;
		case 2:
			cout<<"�����������ѯ��ѧ�ţ�"<<endl;
			cin>>index;
			g.SetID(index);
			pos = s.Locate(g);
			if (pos == 0)
			{
				cout<<"�޵�ǰѧ�ţ�"<<endl;
			}
			else
			{
				cout<<setw(5)<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"�Ա�"<<setw(20)<<"רҵ"<<setw(15)<<"��������"<<endl;
				s.Get(pos).print();
			}
			cout<<"*************************************************"<<endl;
			break;
		case 3:
			cout<<"��������Ҫɾ����ѧ��ѧ��:"<<endl;
			cin>>index;
			g.SetID(index);
			pos = s.Locate(g);
			if (pos == 0)
			{
				cout<<"�޵�ǰѧ�ţ�"<<endl;
			}
			else
			{
				g = s.Delete(pos);
				cout<<"ɾ���ɹ������ڵ�ѧ��ϵͳΪ��"<<endl;
				cout<<"*************************************************"<<endl;
				cout<<setw(5)<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"�Ա�"<<setw(20)<<"רҵ"<<setw(15)<<"��������"<<endl;
				s.PrintLinkList();
				cout<<"*************************************************"<<endl;
			}
			break;
		case 4:
			cout<<"������ѧ�š��������Ա�רҵ����������"<<endl;
			
			cin>>id>>name>>sex>>major>>year>>month>>day;
			g.SetID(id);
			g.SetName(name);
			g.SetSex(sex);
			g.SetMajor(major);
			g.SetBirthday(year,month,day);
			s.Insert(s.ListLength()+1,g);
			cout<<"�޸ĺ�"<<endl;
			cout<<"*************************************************"<<endl;
			cout<<setw(5)<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"�Ա�"<<setw(20)<<"רҵ"<<setw(15)<<"��������"<<endl;
			s.PrintLinkList();
			cout<<"*************************************************"<<endl;
			break;
		case 5:
			cout<<"�����������޸ĵ�ѧ��ѧ�ţ�"<<endl;
			cin>>index;
			g.SetID(index);
			pos = s.Locate(g);
			if (pos == 0)
			{
				cout<<"�޵�ǰѧ�ţ�"<<endl;
			}
			else
			{
			cout<<"�������µ�רҵ��"<<endl;
			cin>>major;
			s.Get(pos).SetMajor(major);
			cout<<"�޸ĺ�"<<endl;
			cout<<"*************************************************"<<endl;
			cout<<setw(5)<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"�Ա�"<<setw(20)<<"רҵ"<<setw(15)<<"��������"<<endl;
			s.PrintLinkList();
			cout<<"*************************************************"<<endl;
			}
			break;
		case 6:
			return 0;
		default:
			cout<<"��������룬����ѡ��"<<endl;
		}
	}
	return 0;

}