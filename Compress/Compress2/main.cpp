#include<iostream>
#include"Huffman.h"
using namespace std;

void runhuffman(char wen[]);
void compare(char wen[]);

void main()
{
	cout<<"**************************************"<<endl;
	cout<<"               ѹ�����               "<<endl;
	cout<<"**************************************"<<endl;
	int c=1;
	char wenjian[20];
	while(c!=0)
	{
		cout<<"1.��������ļ���"<<endl;
		cout<<"2.ѹ������ѹ�ļ�"<<endl;
		cout<<"3.�Ƚ��ļ�"<<endl;
		cout<<"0.�˳�"<<endl;
		cout<<"��ѡ����Ҫִ�еĲ�����";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"�����ļ���Ϊ��";
				   cin>>wenjian;cout<<endl;break;
		    case 2:runhuffman(wenjian);cout<<endl;break;
			case 3:compare(wenjian);break;
			case 0:break;
     	    default:cout<<"��ѡ��Ĳ��������������ѡ��"<<endl;
	
		};

	}

	cout<<"**************************************"<<endl;
	cout<<"                 ��лʹ��             "<<endl;
	cout<<"**************************************"<<endl;
}

void runhuffman(char wen[])
{
	ifstream in(wen);
	int w[MaxSize];
	int weight[MaxSize];   //��Ÿ����ַ���Ƶ��
	int str[MaxSize];      //���A�ļ��и����ַ�������w�е�λ��(�±�)
	int i=0;
	int n=0;
	int cha=0;
	for(int j=0;j<MaxSize;j++)
		w[j]=0;
	for(char ch;in.get(ch);)         
	{
		if((int)ch<0) cha=(int)ch+256;   //���ĵ�ASCII��ֵΪ����������256ʹ����Դ����������
		else cha=(int)ch;
		w[cha]++;
	}
	for(int k=0;k<MaxSize;k++)
		if(w[k]!=0)
		{
			str[n]=k;
			weight[n]=w[k];
			n++;
		}
	HuffmanTree h(weight,str,n);  //�����������
	h.Huffmancode(wen);           //���ù������������ļ�ѹ������ѹ
	h.Huffmandecode();
}

void compare(char wen[])
{
	ifstream ina(wen);
	ifstream inc("c.txt");
    char stringa[100000];
	int i=0;
	int flag=0;
	char stringc[100000];
	int j=0;
    for(char cha;ina>>cha;)    //���ļ�A�����ݶ�������stringa[]
	{
		stringa[i]=cha;
		i++;
	}
	stringa[i]='\0';
	for(char chc;inc>>chc;)    //���ļ�C�����ݶ�������stringc[]
	{
		stringc[j]=chc;
		j++;
	}
	stringc[j]='\0';
	for(int k=0;stringa[k]!='\0'&&stringc[k]!='\0';k++)  
	if(stringa[k]!=stringc[k]) flag=0;
	if(stringa[k]=='\0'&&stringc[k]=='\0') flag=1;
	else flag=0;
    if(flag==0)
		cout<<"A�ļ���C�ļ�����ͬ��ѹ���������"<<endl;
	else
		cout<<"A�ļ���C�ļ���ͬ��ѹ�������ȷ��"<<endl;
}