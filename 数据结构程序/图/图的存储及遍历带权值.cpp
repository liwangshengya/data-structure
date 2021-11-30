#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#define DataType int
const int Max_VERTEXNUM = 20;//ͼ����󶥵���
const int MaxInt = 999;//ͼ�������Ȩֵ
void cinijw(int& vi, int& vj, int& w)
{
	//cout << "������ñ������Ķ��㼰��Ϣ:" << endl;
	cin >> vi >> vj >> w;
}
typedef struct arcl
{
	DataType from;
	DataType to;
	int info;
}ARc;
class AMGraph
{
public:
	AMGraph(DataType a[],int n,int e,ARc b[]);
	~AMGraph();
	void display();
	void DFSTraverse(int v);//DFS�ݹ�
	void DFSTraverse1(int v);//DFS�ǵݹ�
	void BFSTraverse(int v);//BFS
private:
	DataType vertex[Max_VERTEXNUM];
	int arc[Max_VERTEXNUM][Max_VERTEXNUM];
	int vertexNum, arcnum;
	int LocateVex(DataType a)//���Ԫ��a�ڶ��������е�λ��
	{
		for (int i = 0; i < vertexNum; i++)
		{
			if (a == vertex[i])
				return i;
		}
	}
};

AMGraph::AMGraph(DataType a[],int n,int e,ARc b[])
{
	vertexNum = n;
	arcnum = e;
	for (int i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];//���������ʼ��
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] =MaxInt;//���ڽӾ���ȫ����ʼ��Ϊ���ֵ
		}
	}
	for (int i = 0; i < arcnum; i++)
	{
		//int vi, vj, w;
		//cinijw(vi, vj, w);
		int v, r;
		v = LocateVex(b[i].from);
		r= LocateVex(b[i].to);
		arc[v][r] = b[i].info;
		arc[r][v] = b[i].info;//�������뵽�ڽӾ���
	}
}

AMGraph::~AMGraph()
{
}

void AMGraph::display()
{
	cout << "��������Ϊ��" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;//��ӡ��������
	cout << "arc=" << endl;
	cout << " ";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << " " << i;
	}
	cout << endl;//��ӡ�ڽӾ���
	for (int i = 0; i < vertexNum; i++)
	{
		cout << i << " ";
		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[i][j] != MaxInt)
				cout << arc[i][j] << " ";
			else cout << "--" ;
		}
		cout << endl;
	}

}

void AMGraph::DFSTraverse(int v)//DFS�ݹ����
{
	static int visited[Max_VERTEXNUM] = { 0 };
	//��ʼ��visited����Ϊ0��ע��˴���static
	cout << vertex[v] << " ";//����v
	visited[v] = 1;//��v���Ϊ�Է���
	for (int i = 0; i < vertexNum; i++)
	{
		//cout << arc[v][i] << endl;
		if ((arc[v][i] != MaxInt)&& (visited[i] == 0))
			DFSTraverse(i);
	}
}
void AMGraph::DFSTraverse1(int v)
{
	int visited[Max_VERTEXNUM] = { 0 };//
	cout << vertex[v] << " ";
	visited[v] = 1;
	stack<int> s;
	s.push(v);
	while (!s.empty())
	{
		int w, i;
		w = s.top();
		//s.pop();
		for ( i = 0; i < vertexNum; i++)
		{
			if ((arc[w][i] != MaxInt) && (visited[i] == 0))
			{
				s.push(i);
				cout << vertex[i] << " ";
				visited[i] = 1;	
				break;//�������
			}
		}
		if(i==vertexNum)
		{
			s.pop();//���i=vertexnum����i���ڵĽ�㶼��������
		}
	}

}


void AMGraph::BFSTraverse(int v)//BFS����
{
	int visisted[Max_VERTEXNUM] = { 0 };//��ʼ��visited����
	cout << vertex[v] << " ";//������ʹ��Ķ�����Ϣ
	visisted[v] = 1;
	queue<int> q;//�����������Q
	q.push(v);//��ͷԪ�����
	while (!q.empty())
	{
		//�����зǿ�
		int v;
		v = q.front();//����ͷԪ�س��Ӳ��͵�v
		q.pop();
		for (int i = 0; i < vertexNum; i++)
		{
			//�����ж���ɨ��һ��
			if (arc[v][i] != MaxInt && visisted[i] == 0)
			{
				cout << vertex[i]<<" ";
				visisted[i] = 1;
				q.push(i);//��w���
			}
		}
	}
}


//�ڽӱ�洢����ͼ
//�߱�
typedef struct arc {
	int adjvex;////�ڽӵ��򣬶����ڶ�����е��±�
	struct arc* next;//ָ����ָ��߱����һ�����
	int info;//Ȩֵ
}ArcNode;
typedef  struct vet {
	DataType vertex;//����Դ
	ArcNode* firstEdge;//ָ����ָ��߱��еĵ�һ�����
}VertexNode;


class AlGraph
{
public:
	AlGraph(DataType c[],int n,int e,ARc b[]);
	void display();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void DFSTraverse1(int v);
	~AlGraph();

private:
	VertexNode adjList[Max_VERTEXNUM];
	int vertexNum, arcNum;
	int  Locat(DataType c)
	{
		for (int i = 0; i < vertexNum; i++)
		{
			if (c == adjList[i].vertex)
				return i;
		}
	}
};

AlGraph::AlGraph(DataType c[],int n,int e,ARc b[])
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].vertex = c[i];
		adjList[i].firstEdge = NULL;
	}
	for (int k = 0; k < arcNum; k++)
	{
		//int x, y,w;
		//cinijw(x, y, w);
		int i, j;
		i = Locat(b[k].from); j = Locat(b[k].to);
		ArcNode* s1 = new ArcNode;
		s1->adjvex = j;
		s1->info = b[k].info;
		s1->next = adjList[i].firstEdge;
		adjList[i].firstEdge = s1;
		ArcNode* s2 = new ArcNode;
		s2->adjvex = i;
		s2->info = b[k].info;
		s2->next = adjList[j].firstEdge;
		adjList[j].firstEdge = s2;
	}
}

void AlGraph::display()
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << adjList[i].vertex << "����";
		ArcNode* p;
		p = adjList[i].firstEdge;
		while (p)
		{
			cout << p->adjvex<<" "<<p->info << "����";
			p = p->next;
		}
		cout << "NULL" << endl;
	
	}
}

void AlGraph::DFSTraverse(int v)
{
	static int travel[Max_VERTEXNUM] = { 0 };
	cout << adjList[v].vertex << " ";
	travel[v] = 1;
	ArcNode* p = adjList[v].firstEdge;
	while (p)
	{
		if (travel[p->adjvex] == 0)
			DFSTraverse(p->adjvex);
		p = p->next;
	}
}
void AlGraph::DFSTraverse1(int v)
{
	int visited[Max_VERTEXNUM] = { 0 };
	cout << adjList[v].vertex << " ";
	visited[v] = 1;
	ArcNode* p = adjList[v].firstEdge;
	stack<int> s;
	s.push(v);
	while (!s.empty())
	{
		int w;
		w = s.top();
		p = adjList[w].firstEdge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				cout << adjList[p->adjvex].vertex << " ";
				visited[p->adjvex] = 1;
				s.push(p->adjvex);
				p = adjList[p->adjvex].firstEdge;
			}
			else
			{
				p = p->next;
			}
		}
		s.pop();
	}
}

void AlGraph::BFSTraverse(int v)
{
	//��ʼ��visisted����
	int visited[Max_VERTEXNUM] = { 0 };
	//������Ԫ��
	cout << adjList[v].vertex << " ";
	visited[v] = 1;//�ӷ��ʱ�־
	queue<int> q;//�������Q
	q.push(v);//��ͷԪ�����
	while (!q.empty())
	{//�����зǿ�ʱ
		int v;
		v = q.front();
		q.pop();//��ͷԪ�س��ӣ�����v��
		ArcNode* p;//����ָ��pָ�򶥵�v�ı߱�
		p = adjList[v].firstEdge;
		while (p)
		{//���vΪ�����ʣ�����ʶ���w��visisted[w]=1,����w���
			if (visited[p->adjvex] == 0)
			{
				cout << adjList[p->adjvex].vertex << " ";
				visited[p->adjvex] = 1;
				q.push(p->adjvex);
			}
			p = p->next;
			//pָ�򶥵�v����һ���ڽӵ�
		}
	}
}

AlGraph::~AlGraph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode* p;
		while (adjList[i].firstEdge)
		{
			p = adjList[i].firstEdge;
			adjList[i].firstEdge = adjList[i].firstEdge->next;
			delete p;
		}
	}
}


void menu()
{
	cout << "1.�ڽӾ���         2.�ڽӱ�" << endl;
	cout << " 3.�˳�" << endl;
	cout << " ��������� ѡ��" << endl;
}
//int main()
//{
//	int   a[Max_VERTEXNUM];
//	int n, e;
//	ARc ac[Max_VERTEXNUM];
//	cout << "������������ͱ߸�����" << endl;
//	cin >> n >> e;
//	cout << "�����붥��" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < e; i++)
//	{
//		cout<< "�������" << i << "���ߵĶ������Ϣ" << endl;
//		cinijw(ac[i].from, ac[i].to, ac[i].info);
//	}
//	AMGraph m(a, n, e,ac);
//	AlGraph q(a, n, e,ac);
//	menu();
//	int i;
//	while (1)
//	{
//		menu();
//		cin >> i;
//		switch (i)
//		{
//		case 1:
//			m.display();
//			cout << " DFS" << endl;
//			m.DFSTraverse(0);
//			cout << endl;
//			cout << "BFS" << endl;
//			m.BFSTraverse(0);
//			cout << endl;
//			break;
//		case 2:
//			q.display();
//			cout << "DFS";
//			q.DFSTraverse(0);
//			cout << endl;
//			cout << "BFS";
//			q.BFSTraverse(0);
//			cout << endl;
//			break;
//		case 3:return 0;
//		default:
//			break;
//		}
//
//
//
//	}
//
//
//}

int main()
{
	int a[] = { 1,2,3,4,5 };
	ARc b[Max_VERTEXNUM];
	for (int i = 0; i < 4; i++)
	{	
		cinijw(b[i].from, b[i].to, b[i].info);
	}
	AMGraph m(a, 5,4,b);
	m.display();
	m.DFSTraverse1(1);
	m.DFSTraverse(1);
}


/*������������ͱ߸�����
6 10
�����붥��
1 2 3 4 5 6
�������0���ߵĶ������Ϣ
1 2 6
�������1���ߵĶ������Ϣ
1 4 7
�������2���ߵĶ������Ϣ
1 3 6
�������3���ߵĶ������Ϣ
2 4 5
�������4���ߵĶ������Ϣ
2 5 6
�������5���ߵĶ������Ϣ
4 5 8
�������6���ߵĶ������Ϣ
3 6 3
�������7���ߵĶ������Ϣ
4 6 2
�������8���ߵĶ������Ϣ
3 6 4
�������9���ߵĶ������Ϣ
3 5 7
1.�ڽӾ���         2.�ڽӱ�
 3.�˳�
 ��������� ѡ��
1.�ڽӾ���         2.�ڽӱ�
 3.�˳�
 ��������� ѡ��
1
��������Ϊ��
1 2 3 4 5 6
arc=
  0 1 2 3 4 5
0 --6 6 7 ----
1 6 ----5 6 --
2 6 ------7 4
3 7 5 ----8 2
4 --6 7 8 ----
5 ----4 2 ----
 DFS
1 2 4 5 3 6
BFS
1 2 3 4 5 6
1.�ڽӾ���         2.�ڽӱ�
 3.�˳�
 ��������� ѡ��
2
1����2 6����3 7����1 6����NULL
2����4 6����3 5����0 6����NULL
3����4 7����5 4����5 3����0 6����NULL
4����5 2����4 8����1 5����0 7����NULL
5����2 7����3 8����1 6����NULL
6����2 4����3 2����2 3����NULL
DFS1 3 5 4 6 2
BFS1 3 4 2 5 6
1.�ڽӾ���         2.�ڽӱ�
 3.�˳�
 ��������� ѡ��
*/