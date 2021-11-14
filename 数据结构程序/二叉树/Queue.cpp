#include "Queue.h"
Queue::Queue()
{
	msize = MAXQSIZE;
	data = new BiTNode*[msize];
	front = rear = 0;
}
Queue::Queue(int s)
{
	msize = s;
	data = new BiTNode*[msize];
	front = rear = 0;
}
Queue::~Queue()
{
	delete[]data;
}
bool Queue::enQueue(BiTNode *ch)
{
	if (isFull()) return false;
	else
	{
		data[rear] = ch;
		rear = (rear + 1) % MAXQSIZE;
		return true;
	}
}
BiTNode* Queue::deQueue()
{
	BiTNode* ch;
	if (isEmpty()) exit(-1);
	else
	{
		ch = data[front];
		front = (front + 1) % MAXQSIZE;
		return ch;
	}
}
BiTNode* Queue::getQueue()
{
	BiTNode* ch;
	if (isFull()) exit(-1);
	else
	{
		ch = data[front];
		return ch;
	}
}
bool Queue::isEmpty()
{
	if (front == rear) return true;
	else return false;
}
bool Queue::isFull()
{
	if ((rear + 1) % MAXQSIZE == front) return true;
	else return false;
}
void Queue::clearQueue()
{
	rear = front;
}
/*void Queue::displayQueue()
{
	int i;
	for (i = (front + msize) % msize; i < (rear + msize) % msize; i++)
	{
		cout << data[i] << endl;
	}
}
int*/ 
int Queue::queueLength()
{
	return (rear - front + msize) % msize;
}