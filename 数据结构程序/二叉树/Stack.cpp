#include "Stack.h"
Stack::Stack()
{
	size = MAX_SIZE;
	data = new BiTNode*[size];
	top = -1;
}
Stack::~Stack()
{
	delete[]data;
}
void Stack::push(BiTNode *s)
{
	if (isFull()) throw Full();
	else data[++top] = s;
}
BiTNode* Stack::pop()
{
	if (isEmpty()) throw Empty();
	else return data[top--];
}
BiTNode* Stack::gettop()
{
	if (isEmpty()) throw Empty();
	else return data[top];
}
bool Stack::isEmpty()
{
	if (top == -1) return true;
	else return false;
}
bool Stack::isFull()
{
	if (top == size - 1)  return true;
	else return false;
}
void Stack::setNull()
{
	top = -1;
}
//void Stack::display()
//{
//	int i;
//	for ( i = 0; i <= top; i++)
//	{
//		cout <<"("<< data[i].x << "," << data[i].y << ")" << endl;
//	}
//}
