#pragma once
#include<iostream>
using namespace std;
const int MAXQSIZE = 6;
#include"Stack.h"

class Queue
{
private:BiTNode ** data;//ָ�����д洢�ռ�
	   int front;//�����±�
	   int rear;//��β�±�
	   int msize;//��Ŷ��е�����Ĵ�С
public:
	Queue();//����ȱʡ����(MAXQSIZE)�Ķ���
	Queue(int s);//��������λsize�Ķ���
	~Queue();//��ն���,�ͷ��ڴ�
	bool enQueue(BiTNode* ch);//���
	BiTNode* deQueue();//����
	BiTNode* getQueue();//��ȡ��ͷԪ��
	bool isEmpty();//�ж϶����Ƿ�Ϊ��
	bool isFull();//�ж϶����Ƿ�Ϊ��
	void clearQueue();//��ն���
	//void displayQueue();//��ʾ��������
	int queueLength();//��ȡ����Ԫ�ظ���
};

