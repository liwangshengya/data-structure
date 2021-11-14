#pragma once
#include<iostream>
using namespace std;
const int MAXQSIZE = 6;
#include"Stack.h"

class Queue
{
private:BiTNode ** data;//指定队列存储空间
	   int front;//队首下标
	   int rear;//队尾下表
	   int msize;//存放队列的数组的大小
public:
	Queue();//建立缺省长度(MAXQSIZE)的队列
	Queue(int s);//建立长度位size的队列
	~Queue();//清空队列,释放内存
	bool enQueue(BiTNode* ch);//入队
	BiTNode* deQueue();//出队
	BiTNode* getQueue();//读取对头元素
	bool isEmpty();//判断队列是否为空
	bool isFull();//判断队列是否为满
	void clearQueue();//清空队列
	//void displayQueue();//显示队列内容
	int queueLength();//获取队列元素个数
};

