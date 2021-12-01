#include<iostream>
using namespace std;
#define DataType int
const int MaxVertex = 10;
const int MaxEdge = 10;
//边集数组存储图中的边
typedef struct EdgeType
{
	int from,to;//边依附的两个顶点
	int weight;//边上的权值
}Edge;
void cinijw(int& vi, int& vj, int& w)
{
	//cout << "请输入该边依附的顶点及信息:" << endl;
	cin >> vi >> vj >> w;
}
//struct EdgeGraph
//{
//	DataType vertex[MaxVertex];//存放顶点的数据
//	EdgeType edge[MaxEdge];//存放边的数组
//	int vertexNum, edgeNum;//图的顶点数和边数
//};

class EdgeGraph
{
public:
	EdgeGraph(DataType a[],Edge b[], int n, int e);
	friend void Krusal(EdgeGraph& G);
	void sortEdge();//对边集数组进行排序  此函数使用的是选择排序
	void displayEdge();//打印边集数组
	~EdgeGraph();

private:
	DataType vertex[MaxVertex];//存放顶点的数据
	EdgeType edge[MaxEdge];//存放边的数组
	int vertexNum, edgeNum;//图的顶点数和边数
};

EdgeGraph::EdgeGraph(DataType a[], Edge b[], int n, int e)
{
	vertexNum = n;
	edgeNum = e;
	for (int  i = 0; i <vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (int i = 0; i <edgeNum ; i++)
	{
		edge[i] = b[i];
	}
}

void EdgeGraph::sortEdge()
{
	Edge temp;
	for (int i = 0; i <edgeNum; i++)
	{
		for (int j = i; j < edgeNum; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				temp = edge[i];
				edge[i] = edge[j];
				edge[j] = temp;
			}
		}
	}
}

void EdgeGraph::displayEdge()
{
	for (int i = 0; i < edgeNum; i++)
	{
		cout << edge[i].from << " " << edge[i].to << " " << edge[i].weight << endl;
	}
}

EdgeGraph::~EdgeGraph()
{
}
int findRoot(int parent[], int v)
{
	int t = v;
	while (parent[t] > -1)
	{
		t = parent[t];//求顶点t上的双亲直到根节点
	}
	return t;
}
void outputMST(Edge e)
{
	cout << "(" << e.from << "," << e.to << ")" << e.weight << endl;
}
void Krusal(EdgeGraph& G)
{
	int* parent = new int[G.edgeNum];
	for (int i = 0; i < G.edgeNum; i++)
	{
		parent[i] = -1;//初始化parent数组
	}
	for (int i = 0; i < G.edgeNum; i++)
	{
		int num = 0;
		int vex1, vex2;
		vex1 = findRoot(parent, G.edge[i].from);//找到所在生成树的根节点
		vex2 = findRoot(parent, G.edge[i].to);//找到所在生成树的根节点
		if (vex1 != vex2) {//找到两个根节点不相同的生成树，不会构成环
			outputMST(G.edge[i]);//输出边
			parent[vex2] = vex1;//合并生成树
			num++;//记录加边的个数
			if (num == G.vertexNum - 1)//循环G.vertexnum-1次即停止循环，提前返回
			{
				delete [] parent;
				return;
			}
		}
	}
}






int main()
{
	int   a[MaxVertex];
	int n, e;
	Edge c[MaxEdge];
	cout << "请输入结点个数和边个数：" << endl;
	cin >> n >> e;
	cout << "请输入顶点" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < e; i++)
	{
		cout << "请输入第" << i+1 << "条边的顶点和信息" << endl;
		cinijw(c[i].from, c[i].to, c[i].weight);
	}
	EdgeGraph G(a, c, n, e);
	G.displayEdge();
	G.sortEdge();
	cout << endl;
	G.displayEdge();
	Krusal(G);
}
