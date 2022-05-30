#include <iostream>
#include "Graph.cpp"
using namespace std;
inline unsigned __int64 GetCycleCount()
{
__asm _emit 0x0F
__asm _emit 0x31
}

int main()
{
	int v[500] ;
	for (int s = 0;s<500;s++)
		v[s] = s;
	int n = 200;
	int e = 50000;
	GraphType t = undinetwork;
	MGraph<int> a(t,v,n,e);
	/*cout<<"�ڽӱ�Ϊ��"<<endl;
	a.PrintVexs();
	cout<<endl;
	cout<<"�ڽӾ���Ϊ��"<<endl;
	a.PrintEdges();
	EdgeType<int> e1(3,4,5);
	a.InsertEdge(e1,t);
	cout<<"����һ���ߺ�"<<endl;
	a.PrintEdges();
	a.DeleteEdge(e1,t);
	cout<<"ɾ��һ���ߺ�"<<endl;
	a.PrintEdges();
	cout<<"������ȱ���"<<endl;
	a.DFSTraverse();
	cout<<endl;
	cout<<"������ȱ���"<<endl;
	a.BFSTraverse();
	cout<<endl;*//*
	unsigned long t1,t2;
	cout<<"prim�㷨��С��������"<<endl;
	t1 = (unsigned long)GetCycleCount();
	a.Prim(0);
	t2 = (unsigned long)GetCycleCount();
	cout<<"Prim�㷨ʱ��Ϊ(ns)"<<t2-t1<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Kruskal�㷨������С������"<<endl;
	vector < EdgeType<int> > tree;
 	t1 = (unsigned long)GetCycleCount();
	a.Kruskal(tree);
	for (int i = 0;i<tree.size();i++)
		cout<<tree[i].head+1<<"-->"<<tree[i].tail+1<<endl;
	t2 = (unsigned long)GetCycleCount();
	cout<<"Kruskal�㷨ʱ��Ϊ(ns)"<<t2-t1<<endl;*/
	cout<<"Dijkstra�㷨�����·��"<<endl;
	unsigned long t1,t2;
	int path[10000],dist[10000];
	t1 = (unsigned long)GetCycleCount();
	a.Dijkstra(0,path,dist);
	t2 = (unsigned long)GetCycleCount();
	int i = 0;
	while (path[i]>=0&&path[i]<=4)
	{
		cout<<path[i]<<" ";
		i++;
	}
	cout<<endl;
	cout<<"Dijkstra�㷨ʱ��Ϊ(ns)"<<t2-t1<<endl;
	/*cout<<"Floyd�㷨�����·��"<<endl;
	int path1[100][100];
	int D[100][100];
	a.Floyd(path1,D);
	a.Output(path1,D);
	*/return 0;
}