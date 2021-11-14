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

//��ʼ������
Status InitQueue(Queue * queue)
{
	queue->base=(Datetype *)malloc(sizeof(Datetype)*MaxSize);
	if(!queue->base) exit(-1);
	queue->front=queue->rear=0;
	return 1;
}
//����г���
int QueueLength(Queue *q)
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
//�ж϶����Ƿ�Ϊ��
Status isFull(Queue *q)
{
	if((q->rear+1)%MaxSize==q->front) return 1;
	else  return 0;
}
//�ж϶�����Ϊ��
Status isEmpty(Queue *q)
{
	if(q->front==q->rear) return 1;
	else return 0;
}
//���
Status Enqueue(Queue *q,Datetype e)
{
	if(isFull(q)) return 0;//�������Ϊ��,����false
	q->base[q->rear]=e;
	q->rear=(q->rear+1)%MaxSize;
	return 1;
}
//����
Status Dequeue(Queue *q)
{
	if(isEmpty(q)) return 0;
	q->front=(q->front+1)%MaxSize;
	return 1;
}
//�õ���ͷԪ��
Datetype Gethead(Queue *q)
{
	if(isEmpty(q)) exit(-1);
	return q->base[q->front];
}
//���ٶ���
void Destoty(Queue *q)
{
	free(q->base);
}
//����
void Queuedisplay(Queue *q)
{
	int i;
	printf("����Ԫ��Ϊ:");
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
	printf("���г���Ϊ:%d\n",QueueLength(&q));
	printf("��ͷԪ��Ϊ: %d\n",Gethead(&q));
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	Dequeue(&q);
	Queuedisplay(&q);
	
	
	
	
	
}

