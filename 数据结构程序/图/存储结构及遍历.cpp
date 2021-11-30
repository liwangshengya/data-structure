#include<iostream>
using namespace std;
#include<queue>
class MGraph;
class ALGraph;

void cinij(int& vi, int& vj)
{
	cout << "请输入该边依附的顶点编号" << endl;
	cin >> vi >> vj;
}


//无向图的邻接矩阵
#define DataType int
const int MAX_VERTEX = 10;//图的最大顶点数
class MGraph
{
public:
	MGraph();
	MGraph(DataType v[],int n,int e);
	~MGraph();
	void DFSTraverse(int v);//深度优先遍历
	void BFSTraverse(int v);//广度优先遍历
	void display();//打印邻接矩阵和顶点数组
	friend void change(MGraph& a, ALGraph& b);//邻接矩阵转换为邻接表
	friend void change(ALGraph& a, MGraph& b);//邻接表转邻接矩阵
	friend void print(MGraph &a,ALGraph &b);
private:
	DataType vertex[MAX_VERTEX];//顶点数组
	int arc[MAX_VERTEX][MAX_VERTEX];//边
	int vettexNum, arcNum;//实际定点数和边数
};

//析构函数
MGraph::MGraph()
{
	vettexNum = 0;
	arcNum = 0;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		vertex[i] = 0;//顶点数组初始化
	}
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		for (int j = 0; j < MAX_VERTEX; j++)
		{
			arc[i][j] = 0;//初始化邻接矩阵
		}
	}
}
MGraph::MGraph(DataType v[],int n,int e)
{
	vettexNum = n;
	arcNum = e;
	for (int i = 0; i < vettexNum; i++)
	{
		vertex[i] = v[i];//顶点数组初始化
	}
	for (int i = 0; i < vettexNum; i++)
	{
		for (int j = 0; j <vettexNum; j++)
		{
			arc[i][j] = 0;//初始化邻接矩阵
		}
	}
	for (int i = 0; i < arcNum; i++)
	{
		//依次输入每一条边
		int vi, vj;
		cinij(vi, vj);//输入边依附的顶点编号
		arc[vi][vj] = 1;//置有边标志
		arc[vj][vi] = 1;
	}

}

MGraph::~MGraph()
{
}

void MGraph::DFSTraverse(int v)
{
	static int visited[MAX_VERTEX] = { 0 };
	//初始化visite数组为0,(注意此数组的特殊性）
	cout << vertex[v] << "  ";//输出访问的节点信息
	visited[v] = 1;//将v标志为已访问
	for (int i = 0; i <vettexNum; i++)//将v的邻接点访问一遍
	{
		if (arc[v][i] == 1 && visited[i] == 0)
		{
			DFSTraverse(i);//递归访问每个邻接点
		}
	}
}


void MGraph::BFSTraverse(int v)//BFS遍历
{
	int visisted[MAX_VERTEX] = { 0 };//初始化visited数组
	cout << vertex[v] << " ";//输出访问过的顶点信息
	visisted[v] = 1;
	queue<int> q;//定义队列数组Q
	q.push(v);//对头元素入队
	while (!q.empty())
	{
		//当队列非空
		int v;
		v = q.front();//将丢头元素出队并送到v
		q.pop();
		for (int i = 0; i < vettexNum; i++)
		{
			//将所有顶点扫描一遍
			if (arc[v][i] != 0 && visisted[i] == 0)
			{
				cout << vertex[i] << " ";
				visisted[i] = 1;
				q.push(i);//将w入队
			}
		}
	}
}


void MGraph::display()
{
	cout << "顶点数组为：" << endl;
	for (int i = 0; i < vettexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;//打印顶点数组
	cout << "arc=" << endl;
	cout << " ";
	for (int i = 0; i < vettexNum; i++)
	{
		cout << " " << i;
	}
	cout << endl;//打印邻接矩阵
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





//邻接表存储有向图
//边表
typedef struct AdjVexNode
{
	int adivex;//邻接点域，变得终点在定点表中的下标
	struct AdjVexNode* next;//指针域，指向边表中的下一个结点
}ArcNode;
//定点表
typedef struct Vettexnode
{
	DataType vettex;//数据源，存放顶点信息
	ArcNode* firstEdge;//指针域，指向边表中的第一个节点
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
	friend void change(MGraph& a, ALGraph& b);//邻接矩阵转换为邻接表
	friend void change(ALGraph& a, MGraph& b);//邻接表转邻接矩阵

private:
	VettexNode adjList[MAX_VERTEX];//定点表结构体数组
	int vertexNum, arcNum;//顶点个数，边的个数
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
	{//输入定点信息，初始化定点表
		adjList[i].vettex = v[i];
		adjList[i].firstEdge = NULL;
	}
	//输入边的信息存储在边表中
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
		cout << adjList[i].vettex << "——";
		ArcNode* p;
		p = adjList[i].firstEdge;
		while (p)
		{
			cout << p->adivex << "——";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

void ALGraph::DFSTraverse(int v)
{
	//此函数有bug，当输入的结点只有出度为0时，无法进行遍历
	static int visited[MAX_VERTEX] = { 0 };
	//初始化visited数组为0
	cout << adjList[v].vettex << "  ";
	//输出访问过的结点
	visited[v] = 1;
	ArcNode* p;
	p = adjList[v].firstEdge;//工作指针p指向顶点v的边表
	while (p)
	{//用工作指针p依次搜索顶点v的邻接点，如果为被访问，则递归调用此函数
		if (visited[p->adivex] == 0)
		{
			DFSTraverse(p->adivex);
		}
		p = p->next;
	}
}

void ALGraph::BFSTraverse(int v)
{
	//初始化visisted数组
	int visited[MAX_VERTEX] = { 0 };
	//访问首元素
	cout << adjList[v].vettex << " ";
	visited[v] = 1;//加访问标志
	queue<int> q;//定义队列Q
	q.push(v);//队头元素入队
	while (!q.empty())
	{//当队列非空时
		int v;
		v = q.front();
		q.pop();//队头元素出队，存入v中
		ArcNode* p;//工作指针p指向顶点v的边表
		p = adjList[v].firstEdge;
		while (p)
		{//如果v为被访问，则访问顶点w，visisted[w]=1,顶点w入队
			if (visited[p->adivex] == 0)
			{
				cout << adjList[p->adivex].vettex << " ";
				visited[p->adivex] = 1;
				q.push(p->adivex);
			}
			p = p->next;
			//p指向顶点v的下一个邻接点
		}
	}
}

//邻接矩阵转换为邻接表
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
//邻接表转邻接矩阵
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


