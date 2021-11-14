#include<stdio.h>
#include<stdlib.h>
#define Status int
#define MaxSize 10
#define Datetype int
typedef struct queue{
	int front;
	int rear;
	Datetype *base;
}Queue;

//初始化队列
Status InitQueue(Queue * queue)
{
	queue->base=(Datetype *)malloc(sizeof(Datetype)*MaxSize);
	if(!queue->base) exit(-1);
	queue->front=queue->rear=0;
	return 1;
}
//求队列长度
int QueueLength(Queue *q)
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
//判断队列是否为满
Status isFull(Queue *q)
{
	if((q->rear+1)%MaxSize==q->front) return 1;
	else  return 0;
}
//判断队列是为空
Status isEmpty(Queue *q)
{
	if(q->front==q->rear) return 1;
	else return 0;
}
//入队
Status Enqueue(Queue *q,Datetype e)
{
	if(isFull(q)) return 0;//如果队列为满,返回false
	q->base[q->rear]=e;
	q->rear=(q->rear+1)%MaxSize;
	return 1;
}
//出队
Status Dequeue(Queue *q)
{
	if(isEmpty(q)) return 0;
	q->front=(q->front+1)%MaxSize;
	return 1;
}
//得到对头元素
Datetype Gethead(Queue *q)
{
	if(isEmpty(q)) exit(-1);
	return q->base[q->front];
}
//销毁队列
void Destoty(Queue *q)
{
	free(q->base);
}
//遍历
void Queuedisplay(Queue *q)
{
	int i;
	printf("队列元素为:");
	for(int i=0;i<QueueLength(q);i++)
	{
		printf("%d   ",q->base[q->front+i]);
	}
	printf("\n");
}
int main()
{
	Queue q;
	InitQueue(&q);
	Enqueue(&q,1);
	Enqueue(&q,2);
	Enqueue(&q,3);
	Enqueue(&q,4);
	printf("队列长度为:%d\n",QueueLength(&q));
	printf("队头元素为: %d\n",Gethead(&q));
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	
	
	
	
	
}

