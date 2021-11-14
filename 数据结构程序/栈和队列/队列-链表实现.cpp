#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 队列的节点 
struct Node
{
        int data;
        struct Node* next;
};
// 队首队尾指针 
struct Queue
{
        struct Node* front;
        struct Node* rear;
        int size;
};
 //初始化
void QueueInit(struct Queue* queue)
{
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
}
 
int QueueEmpty(struct Queue* queue)
{
        return (queue->size == 0);
}
 //入队
void QueuePush(struct Queue* queue, const int data)
{
        struct Node* node;
        node = (struct Node*)malloc(sizeof(struct Node));
        assert(node != NULL);
        
        node->data = data;
        node->next = NULL;
        
        if(QueueEmpty(queue))
        {
            queue->front = node;
            queue->rear = node;
        }
        else
        {            
            queue->rear->next = node;
            queue->rear = node;
        }
        ++queue->size;
}
 
int QueuePop(struct Queue* queue, int* data)//出队
{
        if (QueueEmpty(queue))
        {
                return 0;
        }
        struct Node* tmp = queue->front;
        *data = queue->front->data;
        queue->front = queue->front->next;
        free(tmp);
        --queue->size;
 
        return 1;
}
 //销毁
void QueueDestroy(struct Queue* queue)
{
     struct Node* tmp;
     while(queue->front)
     {
         tmp = queue->front;
         queue->front = queue->front->next;
         free(tmp);
     }
}
 
//遍历打印队列
void Queuedisplay(struct Queue* queue)
{
    struct Node* p;
    p = queue->front;
	printf("队列元素为:");
    while (p)
    {
        printf("%d   ",p->data);
        p = p->next;
    }
	printf("\n");
}
//得到队头元素
int GetHead(struct Queue* queue)
{
    if(queue->front!=queue->rear)
    {
        return queue->front->data;
    }
}
//得到队列长度
int GetLength(struct Queue* queue)
{
    return queue->size;
}
void shuru(struct Queue* queue)
{
    int i = 0;
    printf("请输入一个整数:(EOF结束输入)\n");

    while (scanf("%d", &i) != EOF)
    {
        //printf("请输入一个整数:\n");
        //scanf("%d", &i);
        QueuePush(queue, i);
        printf("请输入一个整数:(EOF结束输入)\n");
    }
}
void menu()
{
    printf("1.连续输入          2.得到队列长度\n");
    printf("3.出队          	4.得到队列头元素\n");
    printf("5.遍历打印队列      6.销毁退出程序\n"); 
	printf("请输入你的操作\n");

}
int main(void)
{
        struct Queue queue;
        QueueInit(&queue);
 
        // shuru(&queue);
        // Queuedisplay(&queue);
        // printf("\n");

        // printf("对头元素为:%d\n", GetHead(&queue));
        // int l=GetLength(&queue);
        // printf("队列的长的为:%d\n", l);
		
		
		int a;
		int data;
		while(1){
			menu();
			scanf("%d",&a);
			switch(a){
				case 1:shuru(&queue);
					break;
				case 2:
					data=GetLength(&queue);
					printf("队列长度为:%d\n",data);
					break;
				case 3:if(QueuePop(&queue,&data))  
					 printf("出队成功\n");
					 printf("出队的元素为:%d\n",data);
					break;
				case 4:printf("对头元素为:%d\n", GetHead(&queue));
					break;
				case 5:Queuedisplay(&queue);
					break;
				case 6:QueueDestroy(&queue);
					return 0;
				default :
				  printf("请重新输入\n");
				
				
			}
		}
        return 0;
}
