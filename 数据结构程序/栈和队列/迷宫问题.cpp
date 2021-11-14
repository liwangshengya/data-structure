#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define M 8
#define N 8
#define MaxSize (M+2)*(N+2)
#define Status int
typedef struct {
	int intcx, intcy;
}Direction;//����
//���巽������
Direction direct[4] = { {0,1},{1,0},{-1,0},{0,-1} };
//Ѱ��·������
typedef struct {
	int x; int y;
	int pre;
}Data;


typedef struct queue {
	int front;
	int rear;
	Data base[MaxSize];
}Queue;

//��ʼ������
Status InitQueue(Queue* queue)
{
	//if (!queue->base) exit(-1);
	queue->front = queue->rear = 0;
	return 1;
}

//�ж϶����Ƿ�Ϊ��
Status isFull(Queue* q)
{
	if (q->rear==MaxSize) return 1;
	else  return 0;
}
//�ж϶�����Ϊ��
Status isEmpty(Queue* q)
{
	if (q->front == q->rear) return 1;
	else return 0;
}
//���
Status Enqueue(Queue* q, Data &e)
{
	if (isFull(q)) return 0;//�������Ϊ��,����false
	q->rear++;
	q->base[q->rear] = e;
	return 1;
}
//����
Status Dequeue(Queue* q,Data & e)
{
	if (isEmpty(q)) return 0;
	q->front++;
	e = q->base[q->front];
	return 1;
}

//���ٶ���
void Destoty(Queue* q)
{
	free(q->base);
}

void print(Queue* qu)
{
	//printf("%d\n", qu->front);
	for (int i =qu->front; i>0; i=qu->base[i].pre)
	{
		//printf("%d    ", i);
		printf("(%d,%d)\n",qu->base[i].x,qu->base[i].y);
	}
}

bool findpath(int maze[M + 2][N + 2], Direction direct[], Queue * q)
{
	int x, y, di;//��ǰλ��
	int line, col;//��һ���������λ��
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
		printf("���Թ�����û�н�!");
	return 0;
}
