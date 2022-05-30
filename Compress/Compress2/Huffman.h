#include<iostream>
#include<fstream>
using namespace std;

const int MaxSize=512;
struct Node                          //���������Ľ��
{
	int str;                            //��¼�ַ��������е�λ��
	int weight;                         //�ַ�����Ƶ��
	int lchild,rchild,parent;           //������������ָ�����
	char bits[30];                 //�洢���������������
};

class HuffmanTree
{
	Node hufftree[MaxSize];          //��Ź���������������
	int num;                            //�����
public:
	HuffmanTree(int w[],int s[],int n);
	void Select(int n,int &s1,int &s2);
	void Huffmancode(char wen[]);       //����������    
	void Huffmandecode();               //����������
};
void HuffmanTree::Select(int n,int &s1,int &s2)
{
	s1=-1;
	s2=-1;
	for(int i=0;i<=n;i++)
	{
		if(hufftree[i].parent==-1) 
		{
			if(s1==-1) {s1=i;continue;}
	        if(s2==-1) {s2=i;continue;}
	        if(hufftree[i].weight<hufftree[s1].weight)
				s1=i;
	        else if(hufftree[i].weight<hufftree[s2].weight)
				s2=i;
		}
	}
}

HuffmanTree::HuffmanTree(int w[],int s[],int n)
{ 
	num=n;
	int i1,i2;
	i1=i2=0;
	for(int i=0;i<2*num-1;i++)//�ⲿҶ�ӽ����Ϊnum��ʱ���ڲ������Ϊn-1������������������Ҫ�Ľ����Ϊ2*num-1.
	{
		hufftree[i].parent=-1;
		hufftree[i].lchild=-1;
		hufftree[i].rchild=-1;
	}
	for(int j=0;j<num;j++)
	{
		hufftree[j].weight=w[j];
		hufftree[j].str=s[j];
	}
	for(int k=num;k<2*num-1;k++)           //������������
	{
		Select(k-1,i1,i2);   //��hufftree����Ȩֵ��С���������i1��i2 
		hufftree[i1].parent=k;
		hufftree[i2].parent=k;
		hufftree[k].weight=hufftree[i1].weight+hufftree[i2].weight;
		hufftree[k].lchild=i1;
		hufftree[k].rchild=i2;
	}
}

void HuffmanTree::Huffmancode(char wen[])
{
	ifstream in(wen);
	ofstream out("b.txt");
	int start=MaxSize-1;
	int cha=0;
	char cd[MaxSize];           //���һ������
	cd[MaxSize-1]='\0';
	for(int i=0;i<num;i++)      
	{
		start=MaxSize-1;
		int c,f;
		for(c=i,f=hufftree[i].parent;f!=-1;c=f,f=hufftree[f].parent)
		{
			if(hufftree[f].lchild==c)   //�����֧����0
				cd[--start]='0';
			else cd[--start]='1';       //���ҷ�֧����1
		}
		strcpy(hufftree[i].bits,&cd[start]);//������������Ӧ���洢�����������������
	}
    for(char ch;in.get(ch);)  //��A�ļ��и����ַ�ת�����Ӧ�ı��룬д���ļ�B
	{
		if((int)ch<0) cha=(int)ch+256;
		else cha=(int)ch;
		for(int j=0;j<num;j++)
			if(hufftree[j].str==cha)
				out<<hufftree[j].bits;
	}
}

void HuffmanTree::Huffmandecode()
{
	ifstream in("b.txt");
	ofstream out("c.txt");
	int i=2*num-2;
	for(char b;in>>b;)   
	{
		if(b=='0')i=hufftree[i].lchild;
		else i=hufftree[i].rchild;
		if(hufftree[i].lchild==-1)
		{
			out<<(char)hufftree[i].str;
			i=2*num-2;
		}
	}
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

int compare(char wen[])
{
	ifstream ina(wen);
	ifstream inc("3.txt");
    char stringa[100000];
	int i=0;
	int flag=0;
	char stringc[100000];
	int j=0;
	int n = 0;
	char cha,chc;
	while (ina>>cha&&inc>>chc)
	{
		if (cha != chc)
			return  0;
	}
	return 1;
}