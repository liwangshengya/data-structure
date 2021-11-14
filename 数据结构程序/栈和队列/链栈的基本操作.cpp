

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define DateType int
struct Stacknode
{
	DateType data;
	struct Stacknode * next;
};
class LinkStack
{
public:
	LinkStack();//析构函数初始化链栈
	bool Push(DateType e);//入栈
	bool Pop();//出栈
	bool getTop(DateType& e);//获得栈顶元素
	bool isEmpty();//判断是否栈空
	void MakeEmpty();//清空
	friend ostream& operator<<(ostream& cout, LinkStack &ls);//重载<<
	
	~LinkStack();

private:
	Stacknode* top;

};

LinkStack::LinkStack()
{
	top = NULL;
}

bool LinkStack::isEmpty()
{
	if (top == NULL) return true;
	else return false;
}
bool LinkStack::Push(DateType e)
{
	Stacknode* s = new Stacknode;
	s->data = e;
	if (s == NULL) return false;
	s->next = top;
	top = s;
	return true;
}
bool LinkStack::Pop()
{
	if (isEmpty()) return false;
	else 
	{ 
		Stacknode* p = top;
		top = top->next;
		delete p;
		return true;
	}
}

bool LinkStack::getTop(DateType &e)
{
	if (isEmpty()) return false;
	else
	{
		e = top->data;
		return e;
	}
}
void LinkStack::MakeEmpty()
{
	Stacknode* p;
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
}
ostream& operator<<(ostream& cout, LinkStack &ls)
{
	Stacknode* p = ls.top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return cout;
}

LinkStack::~LinkStack()
{
	MakeEmpty();
	if (top) delete top;
}

void menu()
{
	printf("********1.入栈    		2.出栈*********\n");
	printf("********3.得到栈顶元素 	4.打印*********\n");
	printf("********5.判断栈空    	6.退出     *********\n");
}
int main()
{
	LinkStack ls; int choice;
	int a;
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (choice == 6) break;
		switch (choice)
		{
		case 1:
			cout << "请输入入栈数据:" << endl;
			cin >> a;
			if(ls.Push(a)) cout<<" 入栈成功"<<endl;
			cout << "当前栈的数据为:" << ls << endl;
			break;
		case 2:
			if (ls.Pop()) cout << " 出栈成功" << endl;
			else { cout << "失败" << endl; }
			cout << "当前栈的数据为:" << ls << endl;
			break;
		case 3:
			ls.getTop(a);
			cout << "栈顶元素为:" <<a<< endl;
			break;
		case 4:
			cout << "该栈的数据为:" << endl;
			cout << ls << endl;
			break;
		case 5:
			if (ls.isEmpty()) cout << " 当前栈为空" << endl;
			else cout << "栈不为空" << endl;
			break;
		default:
			break;
		}

	}
}
