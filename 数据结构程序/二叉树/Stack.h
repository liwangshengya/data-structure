#pragma once
#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiNode;

class Stack
{
private:
	BiTNode** data;
	int top;
	int size;
public:
	Stack();
	~Stack();
	void push(BiNode *s);
	BiTNode* pop();
	BiTNode* gettop();
	bool isEmpty();
	bool isFull();
	void setNull();
	void display();
	class Empty {};
	class Full {};

};

