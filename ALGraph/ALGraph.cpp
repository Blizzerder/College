#include <iostream>
#include <vector>
#define MaxSize 10000
using namespace std;
enum GraphType{undigraph,digraph,undinetwork,dinetwork};


template<class T>
class SeqQueue
{
	T data[MaxSize];
	int front,rear;
public:
	SeqQueue(){
	front = rear = 0;
}
	void EnQueue(T x){
	if ((rear+1)%MaxSize==front)
	{
		cerr<<"����"<<endl;
		exit(1);
	}
	rear = (rear+1) % MaxSize;
	data[rear] = x;
}
	T DeQueue(){
	if (rear == front)
	{
		cerr<<"����";
		exit(1);
	}
	front = (front+1) % MaxSize;
	return data[front];
}
	T GetQueue(){
	return data[front+1];
}
	bool Empty(){
	return rear == front;
}

};

template <class T>
struct EdgeType
{
	T head , tail;
	int cost;
	EdgeType(T h ,T t ,int c)
	{
		head = h;
		tail = t;
		cost = c;
	}
};

struct EdgeNode			//�߱�Ľ��ṹ����
{
	int adjvex;
	EdgeNode * nextedge;
};

template <class T>		//������Ԫ�ؽṹ����
struct VexNode
{
	T data;
	EdgeNode * firstedge;
};

template <class T>
class ALGraph
{
	int vexnum,edgenum;				//ͼ�еĶ�����������
	vector < VexNode<T> > adjlist;	//�����
	GraphType kind;					//ͼ�����ͱ��

public:
	ALGraph(GraphType t, T vexs[] , int n , int e)	//�����㷨
	{
		EdgeNode * p;
		vexnum = n;
		edgenum = e;
		kind = t;
		adjlist.resize(vexnum);
		for (int i = 0;i < vexnum ; ++i)
		{
			adjlist[i].data = vexs[i];
			adjlist[i].firstedge = 0;
		}
		for (int j = 0; j < edgenum; j++)
		{
			int va,vb;
			cin>>va>>vb;	//�ٽӶ�������
			p = new EdgeNode;//��һ������
			p->adjvex = vb;//
			p->nextedge = adjlist[va].firstedge;//���ڱ�ͷ
			adjlist[va].firstedge = p;
			p = new EdgeNode;//�ڶ�������
			p->adjvex = va;
			p->nextedge = adjlist[vb].firstedge;//���ڱ�ͷ
			adjlist[vb].firstedge = p;
		}
	}
	~ALGraph();
	EdgeNode * FirstEdge(int v)  //���ص�v�������Ӧ�ı߱��ͷָ��
	{
		return adjlist[v].firstedge;
	}
	int VexterNum()				//���ض�������				
	{
		return vexnum;
	}
	int EdgeNum()				//���ر�����
	{
		return edgenum;
	}
	T GetVexValue(int i)		//����ͼ�е�i�������ֵ
	{
		return adjlist[i].data;
	}
	void InsertVex(T v)			//����һ������			
	{
		vexnum++;
		adjlist[vexnum].data = v;
		adjlist[vexnum].firstedge = NULL;
	}
	void RemoveVex(T v)
	{
		int k;
		for (int i = 0;i<vexnum;i++)
			if (adjlist[i].data == v)
			{
				k = i;
				for (int j = i;j<vexnum-1;j++)
					adjlist[j] = adjlist[j+1];
				vexnum--;
			}
		for (i = 0 ; i < vexnum ;i++)
		{
			EdgeNode *q = adjlist[i].firstedge;
			EdgeNode *p = q->next; 
			while (p != NULL)
			{
				if (p->adjvex == k)
				{
					q->nextedge = p->nextedge;
					delete p;
					edgenum--;
				}
			}
		}
	}
	DFSTraverse()
	{
		bool * visited = new bool[vexnum];
		for (int v = 0;v<vexnum;v++)
			visited[v] = false;
		for (v = 0;v<vexnum;v++)
			DFS(v,visited);
		delete []visited;
	}
	DFS(int v , bool * visited)
	{
		cout<<adjlist[v].data<<' ';
		visited[v] = true;
		EdgeNode *p = adjlist[v].firstedge;
		while(p!= NULL)
		{
			int j = p->adjvex;
			if (!visited)
				DFS(j,visited);
			p = p->nextedge;
		}
	}
	BFSTraverse()
	{
		SeqQueue <int , 10> q;
		bool * visited = new bool [vexnum];
		for (int v = 0;v<vexnum;v++)
			visited[v] = false;
		for (v = 0;v<vexnum;v++)
		{
			if (!visited[v])
			{
				cout<<adjlist[v].data<<' ';
				visited[v] = true;
				q.EnQueue(v);
				while (!q.Empty())
				{
					int u = q.DeQueue();
					EdgeNode *p = adjlist[u].firstedge;
					while (p!= NULL)
					{
						if (!visited[p->adjvex])
						{
							q.EnQueue(p->adjvex);
							cout<<adjlist[p->adjvex]<<' ';
							visited[p->adjvex] = true;
						}
						p = p->nextedge;
					}
				}
			}
		}
	}
	Find_All_Path(ALGraph<T> &G , int u , int v , int n , int k)
	{
		path[k] = u;
		visitedFP[u] = true;
		if (u == v && k == n)
		{
			cout<<"Found One Path!\n";
			for (int i = 0;i<=n;i++)
				cout<<path[i]<<endl;
		}
		else
			for (EdgeNode * p =G.FirstEdge(u);p;p = p->nextedge)
			{
				int w = p->adjvex;
				if (!visited[w])
					Find_All_Path(G,w,v,n,k+1);
			}
		visited[u] = false;
		path[k] = 0;
	}
	void TopoSort()
	{
		int * indegree = new int[vexnum];
		SeqQueue <int , 20> s;
		for (int i = 0;i<vexnum;i++)
			indegree[i] = 0;
		EdgeNode * p;
		for (i = 0;i<vexnum;i++)			//��ȵĳ�ʼ��
		{
			p = adjlist[i].firstedge;
			for (;p;p = p->nextedge)
				indegree[p->adjvex]++;
		}
		for (i = 0;i<vexnum;i++)
		{
			if (!indegree[i])
				s.EnQueue(i);
		}
		c = 0;
		while (!s.Empty())
		{
			i = s.DeQueue();
			cout<<adjlist[i].data;
			++c;
			p = adjlist[i].firstedge;
			for(;p;p=p->nextedge)
			{
				indegree[p->adjvex]--;
				if (!indegree[p->adjvex])
					s.EnQueue(p->adjvex);
			}
		}
		if (c<vexnum)
			cout<<"��AOV�����ڻ�"<<endl;
		delete[] indegree;
	}*/
};


