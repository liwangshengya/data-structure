#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
#define M 8
#define N 8
typedef struct{
	int intcx,intcy;
}Direction;//方向
//定义方向数组
Direction direct[4]={{0,1},{1,0},{-1,0},{0,-1}};
//寻找路径函数

typedef struct {
	int x, y;
	int di;
}Box;



class Stack
{
private:
	Box *data;
	int top;
	int size;
public:
	Stack();
	~Stack();
	void push(Box s);
	Box pop();
	Box gettop();
	bool isEmpty();
	bool isFull();
	void setNull();
	void display();
	class Empty{};
	class Full{};
};
Stack::Stack()
{
	size = MAX_SIZE;
	data = new Box[size];
	top = -1;
}
Stack::~Stack()
{
	delete[]data;
}
void Stack::push(Box s)
{
	if (isFull()) throw Full();
	else data[++top] = s;
}
Box Stack::pop()
{
	if (isEmpty()) throw Empty();
	else return data[top--];
}
Box Stack::gettop()
{
	if (isEmpty()) throw Empty();
	else return data[top];
}
bool Stack::isEmpty()
{
	if (top == -1) return true;
	else return false;
}
bool Stack::isFull()
{
	if (top == size - 1)  return true;
	else return false;
}
void Stack::setNull()
{
	top = -1;
}
void Stack::display()
{
	int i;
	for ( i = 0; i <= top; i++)
	{
		cout <<"("<< data[i].x << "," << data[i].y << ")" << endl;
	}
}

bool findPath(int maze[M+2][N+2],Direction d[],Stack &s);
int main()
{
	Stack s;
    int maze[M + 2][N + 2] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
    };
	if (findPath(maze, direct,s)) 
	{	cout << "Find Path" << endl;
		s.display();
		cout << "(" << M<< "," << N<< ")" << endl;
	}
	else cout << "No Path" << endl;
	return 0;
}




bool findPath(int maze[M+2][N+2],Direction d[],Stack &s)
{
	Box temp;
	int x,y,di;//迷宫格子当前处理单元的纵横坐标
	int line,col;//迷宫数组下一处理单元的行坐标和列坐标
	maze[1][1]=-1;
	temp={1,1,-1};
	s.push(temp);
	while(!s.isEmpty())
	{
		temp=s.pop();
		x=temp.x;y=temp.y;di=temp.di+1;
		while(di<4)
		{
			line=x+direct[di].intcx;
			col=y+direct[di].intcy;
			if(maze[line][col]==0)
			{
				temp={x,y,di};
				s.push(temp);
				x=line;y=col;maze[line][col]=-1;
				if(x==M&&y==N) return true;
				else di=0;
			}
			else di++;
		}
	}
	return false;
}


