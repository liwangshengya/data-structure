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
	NODE *head,*tail,*p,*q;//pָ��ǰ���ڴ���Ľ��,qָ��pǰ�ߵ�һ�����
	//����ͷ���
	head=(NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	head->data=-1;
	tail=head;
	for(int i=0;i<m;i++)
	{
		//����β�巨����һ��ѭ������
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
			q->next=p->next;//�����ֵ��˴�������ɾ��
			printf("���ֵ�Ϊ:%d\n",p->data);
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
		//����ʣ2���ڵ�ʱ,ɾ��ǰ��Ľڵ�ʱ�������������,
		//ͷ�ڵ㲻��ָ�����Ľڵ�
	}
	printf("������Ϊ:%d\n",p->data);
	
}

int main()
{
	int m,n;//����Ŀ�뱨������
	printf("�������������ͱ�����:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
}