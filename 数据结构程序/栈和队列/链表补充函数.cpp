#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define ElemType int
//�����������ݽṹ
typedef struct LNode
{
    ElemType data;//������
    struct LNode* next;//ָ����
}LNode, * LinkList;
//**************************������������***************************//
//��ʼ������
Status InitList(LinkList& L)
{
    L = new LNode;//����ͷ��� ����ɾ���Ȳ����Ͳ��طֵ�һ������������
    L->next = NULL;
    return 1;
}
//ostream& operator<<(ostream& cout, ElemType a[]) {
//  
//    for (int i = 0; i < 3; i++)
//    {
//        cout << a[i] << endl;
//    }
//    return cout;
//}

//��ȡ�������� ͷ��������ݣ�����
int ListLength(LinkList L)
{
    LinkList p = L; int sum = 0;
    while (p)
    {
        sum++;
        p = p->next;
    }
    return sum - 1;//ȥ��ͷ���
}
//���ֲ��뷨�������� 
bool ListInsert(LinkList& L, int i, ElemType e)
{
    LNode* s; LinkList p = L; int j = 0;
    while (p && (j < i - 1))//jָ��i-1λ�û���p�Ѿ������ʱ����
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
    {
        printf("����λ����Ч������\n");
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert1(LinkList& L, int i, ElemType e)
{
    LNode* s; LinkList p = L->next; int j = 0;
    LinkList q;
    q = L;
    while (p && (j < i - 1))//jָ��i-1λ�û���p�Ѿ������ʱ����
    {
        q = p;
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
    {
        printf("����λ����Ч������\n");
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p;
    q->next = s;
    return true;
}
//ɾ������ ɾ��λ��i�Ľ�� ��ɾ��i-1֮��Ľ��
bool ListDelete(LinkList& L, int i)
{
    LNode* s; LinkList p = L; int j = 0;
    LinkList q;
    while (p && (j < i - 1))//jָ��i-1λ��
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)//i<1����i>ListLength(L)ʱ,ɾ��λ����Ч
    {
        printf("ɾ��λ����Ч������\n");
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);//�ͷſռ�
    return true;
}
//���Һ��� ��ֵ���� ���ҵ�һ������e�Ľ�� �ɹ����ظý��ָ�룬���򷵻�NULL
LNode* LocateElem(LinkList L, ElemType e)
{
    LNode* p = L;
    while (p && (p->data != e))
    {
        p = p->next;
    }
    return p;
}
//**************************����ʵ�ֺ���**************************//
//�����������
void PrintList(LinkList L)
{
    LinkList p = L->next;//����ͷ���
    if (ListLength(L))
    {
        printf("��ǰ����������Ԫ��:");
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
    {
        printf("��ǰ�������ѿգ�\n");
    }
}
//���빦�ܺ��� ����ListInsert���� 
void Insert(LinkList& L)
{
    int place; ElemType e; bool flag;
    printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
    scanf("%d%d", &place, &e);
    flag = ListInsert(L, place, e);
    if (flag)
    {
        printf("����ɹ�������\n");
        PrintList(L);
    }
}

void Insert1(LinkList& L)
{
    int place; ElemType e; bool flag;
    printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
    scanf("%d%d", &place, &e);
    flag = ListInsert1(L, place, e);
    if (flag)
    {
        printf("����ɹ�������\n");
        PrintList(L);
    }
}

void quicksort(int a[], int low, int high)//�����㷨
{
    int i = low;
    int j = high;
    int temp = a[low];
    while (i < j) {//�������Ϊ������
        while (i < j && a[j] > temp) j--;
        if (i < j) {
            a[i++] = a[j];

        }
        while (i < j && a[i] < temp) i++;
        if (i < j) {
            a[j--] = a[i];
        }
    }
    a[i] = temp;//��
    if (low >= high) return;
    else {
        quicksort(a, low, i - 1);//�ݹ����,������������������
        quicksort(a, i + 1, high);//�����ұ������������
    }
}
//��������:
// ���������ı�������߼�λ��,
// 1.�Ƚ������е�������һȡ������������
// 2.�Ը�����ͨ�����ź�����������
// 3.�ٽ��ź��������������һ���������������
//
bool  Listsort(LinkList& L) {
    LinkList p = L->next;
    int n = ListLength(L);
    if (n==0) return false;
    int i=0;
    ElemType* a = new ElemType[n];
    while (p) {
        a[i++] = p->data;
        p = p->next;
    }
    //cout << a << endl;
    quicksort(a, 0, n - 1);
   // cout << a << endl;
    p = L->next; 
    i = 0;
    while (p) {

        p->data = a[i++];
        p = p->next;
    }
    return true;

}

//ͳ�ƽ��������
int Linkcount(LinkList L)
{
	LinkList p=L->next;
	int count=0;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}
//��ͷ�ڵ��Ϊβ���
bool headrear(LinkList L)
{
	if(L==NULL ||L->next==NULL)
		return false;
	LinkList p,q;
	q=L->next;p=q->next;
	while(p->next)
	{p=p->next;}
	p->next=q;
	L->next=q->next;
	q->next=NULL;
	return true;
}

//ɾ�����ܺ��� ����ListDeleteɾ��
void Delete(LinkList L)
{
    int place; bool flag;
    printf("������Ҫɾ����λ��(��1��ʼ):\n");
    scanf("%d", &place);
    flag = ListDelete(L, place);
    if (flag)
    {
        printf("ɾ���ɹ�������\n");
        PrintList(L);
    }
}
//���ҹ��ܺ��� ����LocateElem����
void Search(LinkList L)
{
    ElemType e; LNode* q;
    printf("������Ҫ���ҵ�ֵ:\n");
    scanf("%d", &e);
    q = LocateElem(L, e);
    if (q)
    {
        printf("�ҵ���Ԫ�أ�\n");
    }
    else
        printf("δ�ҵ���Ԫ�أ�\n");
}


void sort(LinkList& L)
{
    if (Listsort(L)) 
    { 
        cout << "����ɹ�" << endl;
        PrintList(L);
    }
    else cout << "����ʧ��" << endl;
}


void nixushuchu(LinkList L)
{
	int n=Linkcount(L);
	int a[n];
	LinkList p;
	p=L->next;
	for(int i=0;i<n;i++)
	{
		a[i]=p->data;
		p=p->next;
	}
	cout<<"����������Ϊ:";
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void count(LinkList L)
{
	cout<<"������Ľڵ���Ϊ:"<<Linkcount(L)<<endl;
}

void head(LinkList L)
{
	if(headrear(L))
	{
		cout<<"�ɹ����׽ڵ��Ϊβ�ڵ�"<<endl;
		PrintList(L);
	}
	else cout<<"ת��ʧ��"<<endl;
	
}

//�˵�
void menu()
{
    printf("********1.����    		2.ɾ��*********\n");
    printf("********3.����    		4.���*********\n");
    printf("********5.�˳�    		6.ǰ��     *********\n");
    printf("********7.����    		8.������� *********\n");
	printf("********9.�׽ڵ��β  	10.ͳ�ƽ���� *********\n");
}
//������
int main()
{
    LinkList L; int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice)
        {
        case 1:Insert(L); break;
        case 2:Delete(L); break;
        case 3:Search(L); break;
        case 4:PrintList(L); break;
        case 6:Insert(L); break;
        case 7:sort(L); break;
		case 8:nixushuchu(L);break;
		case 9:head(L);break;
		case 10:count(L);break;
        default:printf("������󣡣���\n");
        }
    }
    return 0;
}
