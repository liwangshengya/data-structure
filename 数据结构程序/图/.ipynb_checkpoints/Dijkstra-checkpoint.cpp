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
	AMGraph(DataType a[], int n, int e, ARc b[]);
	~AMGraph();
	void display();
	void DFSTraverse(int v);//DFS递归
	void DFSTraverse1(int v);//DFS非递归
	void BFSTraverse(int v);//BFS
	int getvertexNum() { return vertexNum; }
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
	friend void Dijkstra(AMGraph& G, int startV);
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
		//arc[r][v] = b[i].info;//将边输入到邻接矩阵
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

//找出dist中查找s[i]==0的最小元素值
int finMinDist(int dist[], int s[], int vertexNum)
{
	int min;
	int k;
	for (int i = 0; i < vertexNum; i++)
	{
		if (s[i] == 1)
		{
			continue;
		}
		else
		{
			min = dist[i];
			k = i;
			break;
		}

	}
	for (int i = 0; i < vertexNum; i++)
	{
		if (s[i] == 0 && min > dist[i])
		{
			min = dist[i];
			k = i;
		}
	}
	return k;
}

void display(int dist[], DataType path[], int startV, int vertexNum,DataType vertex[])
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << dist[i] << "    " << path[i] << endl;
	}
	for (int i = 1; i < vertexNum; i++)
	{
		stack<int> s;
		s.push(i);
		int a = path[i];
		s.push(a);
		while (a!=startV)
		{
			a = path[a];
			s.push(a);
		}
		cout << vertex[startV] << "->" << vertex[i]<<"的最短路径为: ";
		while (!s.empty())
		{
			cout << vertex[s.top()] << "   ";
			s.pop();
		}
		cout << "最短路径长度为;"<<dist[i] << endl;
	}
}

/*参数G传入图对象，v为计算的起点*/
void Dijkstra(AMGraph& G, int startV)
{
	int* path = new int[G.vertexNum];
	int* dist = new int[G.vertexNum];
	int* s = new int[G.vertexNum];
	for (int i = 0; i <G.vertexNum; i++)
	{
		s[i] = 0;//初始化集合s，初始化为0
	}
	s[startV] = 1;//将起始顶点放入集合s中，1，代表在集合中，0代表不在集合s中
	for (int i = 0; i < G.vertexNum; i++)
	{
		dist[i] = G.arc[startV][i];//初始化dist数组
		if(dist[i]!=MaxInt)
		{
			path[i] = startV;//初始化path数组
		}
		else
		{
			path[i] = -1;
		}
	}
	int num = 1;//代表集合s中的顶点个数
	while (num<G.vertexNum)
	{
		int min;
		//dist中查找s[i]为0的最小值
		min = finMinDist(dist, s, G.vertexNum);
		s[min] = 1;//将新生成的最小终点加入到集合s
		for (int i = 0; i < G.vertexNum; i++)
		{//修改数组dist和path
			if (s[i] == 0 && (dist[i] > dist[min] + G.arc[min][i]))
			{
				//用以找到的最短路径修改对应的dist
				dist[i] = dist[min] + G.arc[min][i];
				path[i] = min;//用以找到的最短路径修改path
			}
		}
		num++;
	}
	display(dist, path, startV, G.vertexNum,G.vertex);
}


int main() {
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

	Dijkstra(m, 0);

}
/*请输入结点个数和边个数：
5 7 1 2 3 4 5 1 2 10 1 4 30 2 3 50  3 5 10 4 3 20 4 5 60 5 1 100
请输入顶点
请输入第0条边的顶点和信息
请输入第1条边的顶点和信息
请输入第2条边的顶点和信息
请输入第3条边的顶点和信息
请输入第4条边的顶点和信息
请输入第5条边的顶点和信息
请输入第6条边的顶点和信息
顶点数组为：
1 2 3 4 5
arc=
  0 1 2 3 4
0 0 10 --30 --
1 --0 50 ----
2 ----0 --10
3 ----20 0 60
4 100 ------0
请输入起点:0
0    0
10    0
50    3
30    0
60    2
1->2的最短路径为: 1   2   最短路径长度为;10
1->3的最短路径为: 1   4   3   最短路径长度为;50
1->4的最短路径为: 1   4   最短路径长度为;30
1->5的最短路径为: 1   4   3   5   最短路径长度为;60*/
