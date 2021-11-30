#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#define DataType int
const int Max_VERTEXNUM = 20;//图的最大顶点数
const int MaxInt = 999;//图的无穷大权值
void cinijw(int& vi, int& vj, int& w)
{
	//cout << "请输入该边依附的顶点及信息:" << endl;
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
	void DFSTraverse(int v);//DFS递归
	void DFSTraverse1(int v);//DFS非递归
	void BFSTraverse(int v);//BFS
private:
	DataType vertex[Max_VERTEXNUM];
	int arc[Max_VERTEXNUM][Max_VERTEXNUM];
	int vertexNum, arcnum;
	int LocateVex(DataType a)//获得元素a在顶点数组中的位置
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
		vertex[i] = a[i];//顶点数组初始化
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] =MaxInt;//将邻接矩阵全部初始化为最大值
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
		arc[r][v] = b[i].info;//将边输入到邻接矩阵
	}
}

AMGraph::~AMGraph()
{
}

void AMGraph::display()
{
	cout << "顶点数组为：" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;//打印顶点数组
	cout << "arc=" << endl;
	cout << " ";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << " " << i;
	}
	cout << endl;//打印邻接矩阵
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

void AMGraph::DFSTraverse(int v)//DFS递归遍历
{
	static int visited[Max_VERTEXNUM] = { 0 };
	//初始化visited数组为0，注意此处的static
	cout << vertex[v] << " ";//遍历v
	visited[v] = 1;//将v标记为以访问
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
				break;//深度优先
			}
		}
		if(i==vertexNum)
		{
			s.pop();//如果i=vertexnum，与i相邻的结点都访问完了
		}
	}

}


void AMGraph::BFSTraverse(int v)//BFS遍历
{
	int visisted[Max_VERTEXNUM] = { 0 };//初始化visited数组
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
		for (int i = 0; i < vertexNum; i++)
		{
			//将所有顶点扫描一遍
			if (arc[v][i] != MaxInt && visisted[i] == 0)
			{
				cout << vertex[i]<<" ";
				visisted[i] = 1;
				q.push(i);//将w入队
			}
		}
	}
}


//邻接表存储有向图
//边表
typedef struct arc {
	int adjvex;////邻接点域，顶点在定点表中的下标
	struct arc* next;//指针域，指向边表的下一个结点
	int info;//权值
}ArcNode;
typedef  struct vet {
	DataType vertex;//数据源
	ArcNode* firstEdge;//指针域，指向边表中的第一个结点
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
		cout << adjList[i].vertex << "——";
		ArcNode* p;
		p = adjList[i].firstEdge;
		while (p)
		{
			cout << p->adjvex<<" "<<p->info << "——";
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
	//初始化visisted数组
	int visited[Max_VERTEXNUM] = { 0 };
	//访问首元素
	cout << adjList[v].vertex << " ";
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
			if (visited[p->adjvex] == 0)
			{
				cout << adjList[p->adjvex].vertex << " ";
				visited[p->adjvex] = 1;
				q.push(p->adjvex);
			}
			p = p->next;
			//p指向顶点v的下一个邻接点
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
	cout << "1.邻接矩阵。         2.邻接表" << endl;
	cout << " 3.退出" << endl;
	cout << " 请输入你的 选择" << endl;
}
//int main()
//{
//	int   a[Max_VERTEXNUM];
//	int n, e;
//	ARc ac[Max_VERTEXNUM];
//	cout << "请输入结点个数和边个数：" << endl;
//	cin >> n >> e;
//	cout << "请输入顶点" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < e; i++)
//	{
//		cout<< "请输入第" << i << "条边的顶点和信息" << endl;
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


/*请输入结点个数和边个数：
6 10
请输入顶点
1 2 3 4 5 6
请输入第0条边的顶点和信息
1 2 6
请输入第1条边的顶点和信息
1 4 7
请输入第2条边的顶点和信息
1 3 6
请输入第3条边的顶点和信息
2 4 5
请输入第4条边的顶点和信息
2 5 6
请输入第5条边的顶点和信息
4 5 8
请输入第6条边的顶点和信息
3 6 3
请输入第7条边的顶点和信息
4 6 2
请输入第8条边的顶点和信息
3 6 4
请输入第9条边的顶点和信息
3 5 7
1.邻接矩阵。         2.邻接表
 3.退出
 请输入你的 选择
1.邻接矩阵。         2.邻接表
 3.退出
 请输入你的 选择
1
顶点数组为：
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
1.邻接矩阵。         2.邻接表
 3.退出
 请输入你的 选择
2
1——2 6——3 7——1 6——NULL
2——4 6——3 5——0 6——NULL
3——4 7——5 4——5 3——0 6——NULL
4——5 2——4 8——1 5——0 7——NULL
5——2 7——3 8——1 6——NULL
6——2 4——3 2——2 3——NULL
DFS1 3 5 4 6 2
BFS1 3 4 2 5 6
1.邻接矩阵。         2.邻接表
 3.退出
 请输入你的 选择
*/