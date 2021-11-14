#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// ���еĽڵ� 
struct Node
{
        int data;
        struct Node* next;
};
// ���׶�βָ�� 
struct Queue
{
        struct Node* front;
        struct Node* rear;
        int size;
};
 //��ʼ��
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
 //���
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
 
int QueuePop(struct Queue* queue, int* data)//����
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
 //����
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
 
//������ӡ����
void Queuedisplay(struct Queue* queue)
{
    struct Node* p;
    p = queue->front;
	printf("����Ԫ��Ϊ:");
    while (p)
    {
        printf("%d   ",p->data);
        p = p->next;
    }
	printf("\n");
}
//�õ���ͷԪ��
int GetHead(struct Queue* queue)
{
    if(queue->front!=queue->rear)
    {
        return queue->front->data;
    }
}
//�õ����г���
int GetLength(struct Queue* queue)
{
    return queue->size;
}
void shuru(struct Queue* queue)
{
    int i = 0;
    printf("������һ������:(EOF��������)\n");

    while (scanf("%d", &i) != EOF)
    {
        //printf("������һ������:\n");
        //scanf("%d", &i);
        QueuePush(queue, i);
        printf("������һ������:(EOF��������)\n");
    }
}
void menu()
{
    printf("1.��������          2.�õ����г���\n");
    printf("3.����          	4.�õ�����ͷԪ��\n");
    printf("5.������ӡ����      6.�����˳�����\n"); 
	printf("��������Ĳ���\n");

}
int main(void)
{
        struct Queue queue;
        QueueInit(&queue);
 
        // shuru(&queue);
        // Queuedisplay(&queue);
        // printf("\n");

        // printf("��ͷԪ��Ϊ:%d\n", GetHead(&queue));
        // int l=GetLength(&queue);
        // printf("���еĳ���Ϊ:%d\n", l);
		
		
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
					printf("���г���Ϊ:%d\n",data);
					break;
				case 3:if(QueuePop(&queue,&data))  
					 printf("���ӳɹ�\n");
					 printf("���ӵ�Ԫ��Ϊ:%d\n",data);
					break;
				case 4:printf("��ͷԪ��Ϊ:%d\n", GetHead(&queue));
					break;
				case 5:Queuedisplay(&queue);
					break;
				case 6:QueueDestroy(&queue);
					return 0;
				default :
				  printf("����������\n");
				
				
			}
		}
        return 0;
}
