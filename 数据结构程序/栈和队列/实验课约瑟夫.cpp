/*
��n����Χ��һȦ����˳���ţ��ӵ�һ���˿�ʼ��������1����m��������m�����˳�Ȧ�ӣ�
Ȼ����ű��������������������ԭ���ĵڼ��ŵ���λ��

*/

//ѭ������ʵ��
//����һ��ѭ����������ڵ�����������˵ı�ţ�������������ÿ�α���m�����˳������ͷŸýڵ㣬ֱ������ֻʣһ���ڵ㡣
#include <stdio.h>
#include <malloc.h>
 
 /*�����ṹ��*/
 typedef struct Node{
     int Num;
     struct Node *next;
 }JoseNode, *PNode, *HNode;
 
 /**********��ʼ��ѭ��������*********/
 int JoseInit(HNode h)
 {
     if (!h)
     {
         printf("��ʼ���������\n");
         return 0;
     }
     (h)->next = (h);//ѭ��������
     return 1;
 
 }
 
 /*************������������**********/
 int JoseInsert(JoseNode *h, int pos, int x)
 {    
     PNode p=h,q;
     int i=1;
     if (pos == 1)/*β�巨*/
     {
         p->Num = x;
         p->next = p;
         return 1;
     }
     while(i<pos-1)
     {
         p=p->next;
         i++;
     }
     q=(PNode)malloc(sizeof(JoseNode));
     q->Num=x;
     q->next=p->next;
     p->next=q;
     return 1;
 }
 
 /*����*/
 void TraverseList(HNode h, int M)
 {
     int i = 0;
    PNode p=h;
     printf("������˵ı��Ϊ��\n");
     while (i<M)
     {
         printf("%d\t", p->Num);
         p = p->next;
         i++;
     }
     printf("\n");
 }
 /**************���ֺ���****************/
 
 int JoseDelete(HNode h, int M, int k)
 {    int i;
     PNode p=h,q;
     while(M>1)
     {
         for(i=1;i<k-1;i++)
         {
             p=p->next;
         }
         
         q=p->next;
         p->next=q->next;
         printf("���ֵ���Ϊ��%d��\n",q->Num);
         free(q);
 
         p=p->next;
         M--;
     }
     printf("***************��ʤ��Ϊ��%d��***************",p->Num);
     return 1;
 }
int JoseDelete1(HNode h,int M,int k,int l)
{
	PNode p=h,q,w=h;
	int m=M;
	int i=1;
	while(M>(m-l))
	{
		while(i%(k-1)!=0)
		{
			p=p->next;
			i++;
		}
		q=p->next;
		 p->next=q->next;
         printf("���ֵ���Ϊ��%d��\n",q->Num);
         free(q);
		 
		 p=p->next;
		 M--;
		 i++;
	}
	 for(i=1;i<=l;i++)
     {printf("***************��ʤ��Ϊ��%d��***************\n",w->Num);
     	w=w->next ;
	 }
	return 1;
}
 

 
 /***************************************/
 int main()
 {
     int i;//������
     int N;//���������
     int k;//��������
	 int l;//���µ�����
     printf("���������������");
     scanf("%d",&N);
     printf("������������룺");
     scanf("%d",&k);
	  printf("���������µ�������");
     scanf("%d",&l);
 
 /**************�õ�ͷ���****************/
     HNode h = ((HNode)malloc(sizeof(JoseNode)));
 
 /***************��ʼ��������************/
     JoseInit(h);
 
 /******����Ų��뵽ѭ����������******/
     for (i = 1; i <=N; i++)
     {
         JoseInsert(h, i, i);
     }
 /**************����������***************/
     TraverseList(h,N);
 
 /***************���ֺ���************/
     // if(k > 1)
     // JoseDelete(h, N, k);
     // else
     // {
         // for(i = 1; i < N; i++)
             // printf("���ֵ���Ϊ��%d��\n",i);
         // printf("***************��ʤ��Ϊ��%d��***************",N);
     // }
	 JoseDelete1(h,N,k,15);
 
     printf("\n");
     printf("\n");
     return 0;
 }


