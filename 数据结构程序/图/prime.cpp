#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#define DataType int
const int Max_VERTEXNUM = 20;//图的最大顶点数
const int MaxInt = 999;//图的无穷大权值
class AMGraph;
typedef struct edge  ShortEdge;
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
	AMGraph(DataType a[], int n, int e, ARc b[]);
	~AMGraph();
	void display();
	void DFSTraverse(int v);//DFS递归
	void DFSTraverse1(int v);//DFS非递归
	void BFSTraverse(int v);//BFS
	int getvertexNum() { return vertexNum; }
	friend void Prime(AMGraph& G, int start);
	friend void  outputMST(AMGraph& G, int k, ShortEdge shortEdge);
	DataType* getvertx() { return vertex; }
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

AMGraph::AMGraph(DataType a[], int n, int e, ARc b[])
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
			if (i == j) arc[i][j] = 0;
			else
			{
				arc[i][j] = MaxInt;//将邻接矩阵全部初始化为最大值
			}

		}
	}
	for (int i = 0; i < arcnum; i++)
	{
		//int vi, vj, w;
		//cinijw(vi, vj, w);
		int v, r;
		v = LocateVex(b[i].from);
		r = LocateVex(b[i].to);
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
			else cout << "--";
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
		if ((arc[v][i] != MaxInt) && (visited[i] == 0))
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
		for (i = 0; i < vertexNum; i++)
		{
			if ((arc[w][i] != MaxInt) && (visited[i] == 0))
			{
				s.push(i);
				cout << vertex[i] << " ";
				visited[i] = 1;
				break;//深度优先
			}
		}
		if (i == vertexNum)
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
				cout << vertex[i] << " ";
				visisted[i] = 1;
				q.push(i);//将w入队
			}
		}
	}
}


typedef struct edge
{
	DataType vertex;
	int lowcost;
}ShortEdge;

int minEdge(ShortEdge* shortEdge, int vertNum)//寻找最小短边的邻接点k
{
	int temp;
	int k;
	for (int i = 0; i < vertNum; i++)
	{
		if (shortEdge[i].lowcost == 0) continue;
		else
		{
			temp = shortEdge[i].lowcost;
			k = i;
			break;
		}
	}
	for (int i = 0; i < vertNum; i++)
	{
		if (shortEdge[i].lowcost == 0) continue;
		else
		{
			if (temp > shortEdge[i].lowcost)
			{
				temp = shortEdge[i].lowcost;
				k = i;
			}
		}
	}
	return k;
}
void outputMST(AMGraph &G, int k, ShortEdge shortEdge)
{

	cout << "(" <<G.vertex[shortEdge.vertex] << "," << G.vertex[k] << ")" << shortEdge.lowcost << endl;
}
void Prime(AMGraph& G, int start)
{
	int vertexNum = G.getvertexNum();
	ShortEdge* shortEdge = new ShortEdge[vertexNum];
	for (int i = 0; i < vertexNum; i++)//初始化辅助数组shortEdge
	{
		shortEdge[i].lowcost = G.arc[start][i];
		//cout << G.arc[start][i] << endl;
		shortEdge[i].vertex = start;
	}
	shortEdge[start].lowcost = 0;//将起点start放入集合U
	/*for (int i = 0; i < vertexNum; i++)
	{
		cout << shortEdge[i].vertex << "   " << shortEdge[i].lowcost << endl;
	}*/
	for (int i = 0; i < G.vertexNum-1; i++)
	{
		int k = minEdge(shortEdge, vertexNum);////寻找最短边的邻接点k
		//cout << "k=" << k << endl;
		outputMST(G,k, shortEdge[k]);//输出最小生成树路径
		shortEdge[k].lowcost = 0;//将顶点k加入到集合U中
		for (int j = 0; j < vertexNum; j++)//调整数组shortEdge[n]
		{
			if (G.arc[k][j] < shortEdge[j].lowcost)
			{
				shortEdge[j].lowcost = G.arc[k][j];
				shortEdge[j].vertex = k;
			}
		}
		/*for (int i = 0; i < vertexNum; i++)
		{
			cout << shortEdge[i].vertex << "   " << shortEdge[i].lowcost << endl;
		}*/
	}
}






int main()
{
	int   a[Max_VERTEXNUM];
	int n, e;
	ARc ac[Max_VERTEXNUM];
	cout << "请输入结点个数和边个数：" << endl;
	cin >> n >> e;
	cout << "请输入顶点" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < e; i++)
	{
		cout << "请输入第" << i << "条边的顶点和信息" << endl;
		cinijw(ac[i].from, ac[i].to, ac[i].info);
	}

	AMGraph m(a, n, e, ac);
	m.display();
	int start;
	cout << "请输入最小生成树的起始点：";
	cin >> start;
	Prime(m, start);

}
/*请输入结点个数和边个数：
6 9 0 1 2 3 4 5 0 1 34 0 2 46 0 5 19 1 4 12 2 3 17 2 5 25 3 5 25 3 4 38 4 5 26
请输入顶点
请输入第0条边的顶点和信息
请输入第1条边的顶点和信息
请输入第2条边的顶点和信息
请输入第3条边的顶点和信息
请输入第4条边的顶点和信息
请输入第5条边的顶点和信息
请输入第6条边的顶点和信息
请输入第7条边的顶点和信息
请输入第8条边的顶点和信息
顶点数组为：
0 1 2 3 4 5
arc=
  0 1 2 3 4 5
0 0 34 46 ----19
1 34 0 ----12 --
2 46 --0 17 --25
3 ----17 0 38 25
4 --12 --38 0 26
5 19 --25 25 26 0
请输入最小生成树的起始点：3
(3,2)17
(3,5)25
(5,0)19
(5,4)26
(4,1)12*/
