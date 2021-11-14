#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
//typedef struct BiTNode {
//	char data;
//	struct BiTNode* lchild, *rchild;
//}BiNode;

BiNode* InitBiNode()
{
	BiNode *T;
	char c;
	scanf("%c", &c);
	if (c == '#') T = NULL;
	else
	{
		T = (BiNode*)malloc(sizeof(BiNode));
		//T->data = c;
		T->lchild = InitBiNode();
		T->data = c;
		T->rchild= InitBiNode();
	}
	return T;
}

void visit(char data)
{
	printf("%c\n", data);
}
//先序
void PreBiNode(BiNode* T)
{
	if (T)
	{
		visit(T->data);
		PreBiNode(T->lchild);
		PreBiNode(T->rchild);
	}
}
void PreBiNode1(BiNode* T)
{
	Stack s;
	BiTNode* p, * q;
	p = T;
	q = new BiNode;
	while (p || !s.isEmpty())
	{
		if (p)
		{
			visit(p->data);
			s.push(p);
			p = p->lchild;
		}
		else
		{
			q = s.pop();
			//visit(q->data);
			p = q->rchild;
		}
	}
}
//中序
void InBiNode(BiNode* T)
{
	if (T) {
		InBiNode(T->lchild);
		visit(T->data);
		InBiNode(T->rchild);
	}
}

void InBiNode1(BiNode* T)
{
	Stack s;
	BiTNode* p, * q;
	p = T;
	q = new BiNode;
	while (p || !s.isEmpty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			q = s.pop();
			visit(q->data);
			p = q->rchild;
		}
	}
}

//后序
void PostBiNode(BiNode* T)
{
	if (T) {
		PostBiNode(T->lchild);
		PostBiNode(T->rchild);
		visit(T->data);
	}
}
void PostBiNode1(BiNode* T)
{
	Stack s;
	BiTNode* p, * q;
	p = NULL;	
	q = T;
	while ((q != NULL) || (!s.isEmpty()))
	{
		if (q != NULL)
		{
			s.push(q);
			q = q->lchild;
		}
		else
		{
			q = s.gettop();
			if ((q->rchild != NULL) && (q->rchild != p))
			{
				q = q->rchild;
				s.push(q);
				q = q->lchild;
			}
			else
			{
				q = s.pop();
				visit(q->data);
				p = q;
				q = NULL;
			}
		}
	}
	
}
//层序遍历二叉树
void LeverBiNode(BiTNode* T)
{
	Queue q;
	BiTNode* p;
	if (T == NULL) return;
	q.enQueue(T);//根指针入队
	while (!q.isEmpty())
	{
		p= q.deQueue();
		visit(p->data);
		//左孩子存在，左孩子入队
		if (p->lchild) q.enQueue(p->lchild);
		//右孩子存在，右孩子入队
		if (p->rchild) q.enQueue(p->rchild);

	}
}

//二叉树深度计算
int GetLength(BiNode *T)
{
	if (T == NULL) return 0;
	else {
		int m, n;
		m = GetLength(T->lchild);
		n = GetLength(T->rchild);
		return (m > n) ? m + 1 : n + 1;
	}
}


int main()
{
	BiNode* T;
	T = InitBiNode();
	printf("先序遍历二叉树:\n");
	PreBiNode(T);
	printf("非递归先序遍历二叉树：\n");
	PreBiNode1(T);
	printf("中序遍历二叉树:\n");
	InBiNode(T);
	printf("非递归中序遍历二叉树：\n");
	InBiNode1(T);
	printf("后序遍历二叉树:\n");
	PostBiNode(T);
	printf("非递归后序遍历二叉树\n");
	PostBiNode1(T);
	printf("层序遍历二叉树：\n");
	LeverBiNode(T);
	printf("该二叉树的深度为：%d", GetLength(T));
	return 0;
}