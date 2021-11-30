#include<iostream>
using namespace std;
#include<queue>
class MGraph;
class ALGraph;

void cinij(int& vi, int& vj)
{
	cout << "������ñ������Ķ�����" << endl;
	cin >> vi >> vj;
}


//����ͼ���ڽӾ���
#define DataType int
const int MAX_VERTEX = 10;//ͼ����󶥵���
class MGraph
{
public:
	MGraph();
	MGraph(DataType v[],int n,int e);
	~MGraph();
	void DFSTraverse(int v);//������ȱ���
	void BFSTraverse(int v);//������ȱ���
	void display();//��ӡ�ڽӾ���Ͷ�������
	friend void change(MGraph& a, ALGraph& b);//�ڽӾ���ת��Ϊ�ڽӱ�
	friend void change(ALGraph& a, MGraph& b);//�ڽӱ�ת�ڽӾ���
	friend void print(MGraph &a,ALGraph &b);
private:
	DataType vertex[MAX_VERTEX];//��������
	int arc[MAX_VERTEX][MAX_VERTEX];//��
	int vettexNum, arcNum;//ʵ�ʶ������ͱ���
};

//��������
MGraph::MGraph()
{
	vettexNum = 0;
	arcNum = 0;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		vertex[i] = 0;//���������ʼ��
	}
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		for (int j = 0; j < MAX_VERTEX; j++)
		{
			arc[i][j] = 0;//��ʼ���ڽӾ���
		}
	}
}
MGraph::MGraph(DataType v[],int n,int e)
{
	vettexNum = n;
	arcNum = e;
	for (int i = 0; i < vettexNum; i++)
	{
		vertex[i] = v[i];//���������ʼ��
	}
	for (int i = 0; i < vettexNum; i++)
	{
		for (int j = 0; j <vettexNum; j++)
		{
			arc[i][j] = 0;//��ʼ���ڽӾ���
		}
	}
	for (int i = 0; i < arcNum; i++)
	{
		//��������ÿһ����
		int vi, vj;
		cinij(vi, vj);//����������Ķ�����
		arc[vi][vj] = 1;//���б߱�־
		arc[vj][vi] = 1;
	}

}

MGraph::~MGraph()
{
}

void MGraph::DFSTraverse(int v)
{
	static int visited[MAX_VERTEX] = { 0 };
	//��ʼ��visite����Ϊ0,(ע�������������ԣ�
	cout << vertex[v] << "  ";//������ʵĽڵ���Ϣ
	visited[v] = 1;//��v��־Ϊ�ѷ���
	for (int i = 0; i <vettexNum; i++)//��v���ڽӵ����һ��
	{
		if (arc[v][i] == 1 && visited[i] == 0)
		{
			DFSTraverse(i);//�ݹ����ÿ���ڽӵ�
		}
	}
}


void MGraph::BFSTraverse(int v)//BFS����
{
	int visisted[MAX_VERTEX] = { 0 };//��ʼ��visited����
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
		for (int i = 0; i < vettexNum; i++)
		{
			//�����ж���ɨ��һ��
			if (arc[v][i] != 0 && visisted[i] == 0)
			{
				cout << vertex[i] << " ";
				visisted[i] = 1;
				q.push(i);//��w���
			}
		}
	}
}


void MGraph::display()
{
	cout << "��������Ϊ��" << endl;
	for (int i = 0; i < vettexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;//��ӡ��������
	cout << "arc=" << endl;
	cout << " ";
	for (int i = 0; i < vettexNum; i++)
	{
		cout << " " << i;
	}
	cout << endl;//��ӡ�ڽӾ���
	for (int i = 0; i <vettexNum; i++)
	{
		cout << i << " ";
		for (int j = 0; j < vettexNum; j++)
		{
			cout << arc[i][j] << " ";
		}
		cout << endl;
	}

}





//�ڽӱ�洢����ͼ
//�߱�
typedef struct AdjVexNode
{
	int adivex;//�ڽӵ��򣬱���յ��ڶ�����е��±�
	struct AdjVexNode* next;//ָ����ָ��߱��е���һ�����
}ArcNode;
//�����
typedef struct Vettexnode
{
	DataType vettex;//����Դ����Ŷ�����Ϣ
	ArcNode* firstEdge;//ָ����ָ��߱��еĵ�һ���ڵ�
}VettexNode;
class ALGraph
{
public:
	ALGraph(DataType v[],int n,int e);
	ALGraph();
	~ALGraph();
	void display();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	friend void change(MGraph& a, ALGraph& b);//�ڽӾ���ת��Ϊ�ڽӱ�
	friend void change(ALGraph& a, MGraph& b);//�ڽӱ�ת�ڽӾ���

private:
	VettexNode adjList[MAX_VERTEX];//�����ṹ������
	int vertexNum, arcNum;//����������ߵĸ���
};

ALGraph::ALGraph()
{
	vertexNum = 0;
	arcNum = 0;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		adjList[i].vettex = 0;
		adjList[i].firstEdge = NULL;
	}
}
ALGraph::ALGraph(DataType v[],int n,int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
	{//���붨����Ϣ����ʼ�������
		adjList[i].vettex = v[i];
		adjList[i].firstEdge = NULL;
	}
	//����ߵ���Ϣ�洢�ڱ߱���
	for (int i = 0; i < arcNum; i++)
	{
		int vi, vj;
		cinij(vi, vj);
		ArcNode *s = new ArcNode;
		s->adivex = vj;
		s->next = adjList[vi].firstEdge;
		adjList[vi].firstEdge = s;
	}
}

ALGraph::~ALGraph()
{
	for (int i = 0; i < vertexNum ;i++)
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

void ALGraph::display()
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << adjList[i].vettex << "����";
		ArcNode* p;
		p = adjList[i].firstEdge;
		while (p)
		{
			cout << p->adivex << "����";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

void ALGraph::DFSTraverse(int v)
{
	//�˺�����bug��������Ľ��ֻ�г���Ϊ0ʱ���޷����б���
	static int visited[MAX_VERTEX] = { 0 };
	//��ʼ��visited����Ϊ0
	cout << adjList[v].vettex << "  ";
	//������ʹ��Ľ��
	visited[v] = 1;
	ArcNode* p;
	p = adjList[v].firstEdge;//����ָ��pָ�򶥵�v�ı߱�
	while (p)
	{//�ù���ָ��p������������v���ڽӵ㣬���Ϊ�����ʣ���ݹ���ô˺���
		if (visited[p->adivex] == 0)
		{
			DFSTraverse(p->adivex);
		}
		p = p->next;
	}
}

void ALGraph::BFSTraverse(int v)
{
	//��ʼ��visisted����
	int visited[MAX_VERTEX] = { 0 };
	//������Ԫ��
	cout << adjList[v].vettex << " ";
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
			if (visited[p->adivex] == 0)
			{
				cout << adjList[p->adivex].vettex << " ";
				visited[p->adivex] = 1;
				q.push(p->adivex);
			}
			p = p->next;
			//pָ�򶥵�v����һ���ڽӵ�
		}
	}
}

//�ڽӾ���ת��Ϊ�ڽӱ�
void change(MGraph& a, ALGraph& b)
{
	b.vertexNum = a.vettexNum;
	b.arcNum = a.arcNum;
	for (int i = 0; i < a.vettexNum; i++)
	{
		b.adjList[i].vettex = a.vertex[i];
		b.adjList[i].firstEdge = NULL;
		for (int j = 0; j < a.vettexNum; j++)
		{
			if (a.arc[i][j])//&&i<j
			{
				ArcNode* s = new ArcNode;
				s->adivex = j;
				s->next = b.adjList[i].firstEdge;
				b.adjList[i].firstEdge = s;
			}
		}
	}
}
//�ڽӱ�ת�ڽӾ���
void change(ALGraph& a, MGraph& b)
{
	b.vettexNum = a.vertexNum;
	b.arcNum = a.arcNum;
	for (int i = 0; i < a.vertexNum; i++)
	{
		b.vertex[i] = a.adjList[i].vettex;
		ArcNode* p;
		p = a.adjList[i].firstEdge;
		while (p)
		{
			b.arc[i][p->adivex] = 1;
			//b.arc[p->adivex][i] = 1;
			p = p->next;
		}
	}
}



int main()
{
	int a[] = { 0,1,2,3 };
	/*ALGraph m;
	MGraph b(a,4,4);
	b.display();
	change(b, m);
	m.display();*/
	ALGraph m(a, 4, 4);
	m.display();
	m.DFSTraverse(3);
	m.BFSTraverse(3);
	
}


