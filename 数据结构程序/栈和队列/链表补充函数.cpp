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
//单链表结点数据结构
typedef struct LNode
{
    ElemType data;//数据域
    struct LNode* next;//指针域
}LNode, * LinkList;
//**************************基本操作函数***************************//
//初始化函数
Status InitList(LinkList& L)
{
    L = new LNode;//生成头结点 这样删除等操作就不必分第一个结点和其他了
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

//获取单链表长度 头结点无数据，不算
int ListLength(LinkList L)
{
    LinkList p = L; int sum = 0;
    while (p)
    {
        sum++;
        p = p->next;
    }
    return sum - 1;//去除头结点
}
//哪种插入法？？？？ 
bool ListInsert(LinkList& L, int i, ElemType e)
{
    LNode* s; LinkList p = L; int j = 0;
    while (p && (j < i - 1))//j指到i-1位置或者p已经到最后时跳出
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
    {
        printf("插入位置无效！！！\n");
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
    while (p && (j < i - 1))//j指到i-1位置或者p已经到最后时跳出
    {
        q = p;
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)//i<1或者i>ListLength(L)+1时,插入位置无效 不调用ListLength,提高效率
    {
        printf("插入位置无效！！！\n");
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p;
    q->next = s;
    return true;
}
//删除函数 删除位置i的结点 即删除i-1之后的结点
bool ListDelete(LinkList& L, int i)
{
    LNode* s; LinkList p = L; int j = 0;
    LinkList q;
    while (p && (j < i - 1))//j指到i-1位置
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)//i<1或者i>ListLength(L)时,删除位置无效
    {
        printf("删除位置无效！！！\n");
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);//释放空间
    return true;
}
//查找函数 按值查找 查找第一个等于e的结点 成功返回该结点指针，否则返回NULL
LNode* LocateElem(LinkList L, ElemType e)
{
    LNode* p = L;
    while (p && (p->data != e))
    {
        p = p->next;
    }
    return p;
}
//**************************功能实现函数**************************//
//遍历输出函数
void PrintList(LinkList L)
{
    LinkList p = L->next;//跳过头结点
    if (ListLength(L))
    {
        printf("当前单链表所有元素:");
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    else
    {
        printf("当前单链表已空！\n");
    }
}
//插入功能函数 调用ListInsert插入 
void Insert(LinkList& L)
{
    int place; ElemType e; bool flag;
    printf("请输入要插入的位置(从1开始)及元素:\n");
    scanf("%d%d", &place, &e);
    flag = ListInsert(L, place, e);
    if (flag)
    {
        printf("插入成功！！！\n");
        PrintList(L);
    }
}

void Insert1(LinkList& L)
{
    int place; ElemType e; bool flag;
    printf("请输入要插入的位置(从1开始)及元素:\n");
    scanf("%d%d", &place, &e);
    flag = ListInsert1(L, place, e);
    if (flag)
    {
        printf("插入成功！！！\n");
        PrintList(L);
    }
}

void quicksort(int a[], int low, int high)//快排算法
{
    int i = low;
    int j = high;
    int temp = a[low];
    while (i < j) {//将数组分为三部分
        while (i < j && a[j] > temp) j--;
        if (i < j) {
            a[i++] = a[j];

        }
        while (i < j && a[i] < temp) i++;
        if (i < j) {
            a[j--] = a[i];
        }
    }
    a[i] = temp;//轴
    if (low >= high) return;
    else {
        quicksort(a, low, i - 1);//递归调用,对轴左边数组进行排序
        quicksort(a, i + 1, high);//对轴右边数组进行排序
    }
}
//链表排序:
// 本函数不改变链表的逻辑位置,
// 1.先将链表中的数据逐一取出放置数组中
// 2.对该数组通过快排函数进行排序
// 3.再将排好序的数组数组逐一放置链表的数据区
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

//统计结点数函数
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
//将头节点变为尾结点
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

//删除功能函数 调用ListDelete删除
void Delete(LinkList L)
{
    int place; bool flag;
    printf("请输入要删除的位置(从1开始):\n");
    scanf("%d", &place);
    flag = ListDelete(L, place);
    if (flag)
    {
        printf("删除成功！！！\n");
        PrintList(L);
    }
}
//查找功能函数 调用LocateElem查找
void Search(LinkList L)
{
    ElemType e; LNode* q;
    printf("请输入要查找的值:\n");
    scanf("%d", &e);
    q = LocateElem(L, e);
    if (q)
    {
        printf("找到该元素！\n");
    }
    else
        printf("未找到该元素！\n");
}


void sort(LinkList& L)
{
    if (Listsort(L)) 
    { 
        cout << "排序成功" << endl;
        PrintList(L);
    }
    else cout << "排序失败" << endl;
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
	cout<<"逆序输出结果为:";
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void count(LinkList L)
{
	cout<<"该链表的节点数为:"<<Linkcount(L)<<endl;
}

void head(LinkList L)
{
	if(headrear(L))
	{
		cout<<"成功吧首节点变为尾节点"<<endl;
		PrintList(L);
	}
	else cout<<"转换失败"<<endl;
	
}

//菜单
void menu()
{
    printf("********1.插入    		2.删除*********\n");
    printf("********3.查找    		4.输出*********\n");
    printf("********5.退出    		6.前插     *********\n");
    printf("********7.排序    		8.逆序输出 *********\n");
	printf("********9.首节点变尾  	10.统计结点数 *********\n");
}
//主函数
int main()
{
    LinkList L; int choice;
    InitList(L);
    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
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
        default:printf("输入错误！！！\n");
        }
    }
    return 0;
}
