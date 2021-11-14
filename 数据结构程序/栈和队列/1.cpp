#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define M 8
#define N 8
#define MaxSize (M+2)*(N+2)
#define Status int
typedef struct {
	int intcx, intcy;
}Direction;//方向
//定义方向数组
Direction direct[4] = { {0,1},{1,0},{-1,0},{0,-1} };
//寻找路径函数
typedef struct {
	int x; int y;
	int pre;
}Data;


typedef struct queue {
	int front;
	int rear;
	Data base[MaxSize];
}Queue;

//初始化队列
Status InitQueue(Queue* queue)
{
	//if (!queue->base) exit(-1);
	queue->front = queue->rear = 0;
	return 1;
}

//判断队列是否为满
Status isFull(Queue* q)
{
	if (q->rear==MaxSize) return 1;
	else  return 0;
}
//判断队列是为空
Status isEmpty(Queue* q)
{
	if (q->front == q->rear) return 1;
	else return 0;
}
//入队
Status Enqueue(Queue* q, Data &e)
{
	if (isFull(q)) return 0;//如果队列为满,返回false
	//q->rear++;
	q->base[q->rear] = e;
	q->rear++;
	return 1;
}
//出队
Status Dequeue(Queue* q,Data & e)
{
	if (isEmpty(q)) return 0;
	//q->front++;
	e = q->base[q->front];
	q->front++;
	return 1;
}

//销毁队列
void Destoty(Queue* q)
{
	free(q->base);
}

void print(Queue* qu)
{
	int i;
	for ( i = qu->front-1; i > 0; i = qu->base[i].pre-1)
	{
		//printf("%d ", i);
		printf("(%d,%d)\n", qu->base[i].x, qu->base[i].y);
	}
	printf("(%d,%d)\n", qu->base[i].x, qu->base[i].y);
}

bool findpath(int maze[M + 2][N + 2], Direction direct[], Queue * q)
{
	int x, y, di;//当前位置
	int line, col;//下一个待处理的位置
	Data temp;
	temp = { M,N,-1 };
	maze[M][N] = -1;
	Enqueue(q, temp);
	while (!isEmpty(q))
	{
		Dequeue(q, temp);
		x = temp.x; y = temp.y;
		di = 0;
		if (x == 1 && y == 1)
		{
			print(q);
			//printf("%d %d",q->base[30].x,q->base[30].y);
			return true;
		}

		while (di<4)
		{
			line = x + direct[di].intcx;
			col = y + direct[di].intcy;
			if (maze[line][col] == 0)
			{
				temp = { line,col,q->front };
				Enqueue(q, temp);
				maze[line][col] = -1;
			}
			di++;
		}
	}
	return false;

}


int main()
{

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
	Queue q;
	InitQueue(&q);
	if (!findpath(maze, direct, &q))
		printf("该迷宫问题没有解!");
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#define MaxSize 100
//#define M 8
//#define N 8
//typedef struct
//{
//    int i, j;    //方块在迷宫中的坐标位置(i,j)         
//    int pre;    //本路径中上一方块在队列中的下标   
//} SqQueue;
//SqQueue Qu[MaxSize];  //定义顺序非循环队列
//int front = 0, rear = 0;
//int mg[M + 2][N + 2] =
//{
//    {1,1,1,1,1,1,1,1,1,1},
//    {1,0,0,1,0,0,0,1,0,1},
//    {1,0,0,1,0,0,0,1,0,1},
//    {1,0,0,0,0,1,1,0,0,1},
//    {1,0,1,1,1,0,0,0,0,1},
//    {1,0,0,0,1,0,0,0,0,1},
//    {1,0,1,0,0,0,1,0,0,1},
//    {1,0,1,1,1,0,1,1,0,1},
//    {1,1,0,0,0,0,0,0,0,1},
//    {1,1,1,1,1,1,1,1,1,1}
//};
//void print(SqQueue Qu[], int front)
//{
//    int k = 0;
//    for (int i = front; i > 0; i = Qu[i].pre)
//    {
//        printf("(%d,%d) ", Qu[i].i, Qu[i].j);
//        k++;
//        if (k % 5 == 0)   //每输出每5个方块后换一行
//            printf("\n");
//    }
//}
//bool mgpath1(int xi, int yi, int xe, int ye)	//搜索路径为:(xi,yi)->(xe,ye)
//{
//    int i, j, di, i1, j1;
//    rear++;
//    Qu[rear].i = xi; Qu[rear].j = yi; Qu[rear].pre = -1; //(xi,yi)进队
//    mg[xi][yi] = -1;		        //将其赋值-1,以避免回过来重复搜索
//    while (front != rear)		    //队不空循环
//    {
//        front++;
//        i = Qu[front].i; j = Qu[front].j; //出队
//        if (i == xe && j == ye)	    //找到了出口,输出路径
//        {
//            print(Qu, front);	//调用print函数输出路径
//            return true;		//找到一条路径时返回真
//        }
//        for (di = 0; di < 4; di++)    //循环扫描每个方位
//        {
//            switch (di)
//            {
//            case 0:i1 = i - 1;   j1 = j; break;
//            case 1:i1 = i;  j1 = j + 1; break;
//            case 2:i1 = i + 1;  j1 = j; break;
//            case 3:i1 = i;   j1 = j - 1; break;
//            }
//            if (mg[i1][j1] == 0)
//            {
//                rear++;
//                Qu[rear].i = i1; Qu[rear].j = j1;
//                Qu[rear].pre = front;	//(i1，j1)方块进队
//                mg[i1][j1] = -1;	//将其赋值-1
//            }
//        }//for
//    }//while
//    return false;
//}//mgpath1
//
//int main()
//{
//    if (!mgpath1(M, N, 1, 1))
//        printf("该迷宫问题没有解!");
//    return 1;
//}