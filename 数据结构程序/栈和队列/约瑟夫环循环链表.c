#include<stdio.h>
#include<stdlib.h>
typedef struct nodde
{
	int data;
	struct node* next;
}NODE;

void yuesefu(int m,int n)
{
	int i;
	NODE *head,*tail,*p,*q;//p指向当前正在处理的结点,q指向p前边的一个结点
	//创建头结点
	head=(NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	head->data=-1;
	tail=head;
	for(int i=0;i<m;i++)
	{
		//采用尾插法创建一个循环链表
		p=(NODE *)malloc(sizeof(NODE));
		p->data=i+1;
		p->next=head->next;
		tail->next=p;
		tail=p;
	}
	
	p=head->next;
	q=head;
	i=1;
	//while(q!=p)
	while(m>1)
	{
		if(i==n)
		{
			q->next=p->next;//将出局的人从链表中删除
			printf("出局的为:%d\n",p->data);
			free(p);
			p=q->next;
			m--;
			i=1;
		}
		else
		{
			q=p;
			p=p->next;
			i++;
		}
		head->next=q;
		//当仅剩2个节点时,删除前面的节点时会造成链表不完整,
		//头节点不在指向后面的节点
	}
	printf("最后的人为:%d\n",p->data);
	
}

int main()
{
	int m,n;//总数目与报数的数
	printf("请输入总人数和报的数:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
}