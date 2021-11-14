

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
	LinkStack();//����������ʼ����ջ
	bool Push(DateType e);//��ջ
	bool Pop();//��ջ
	bool getTop(DateType& e);//���ջ��Ԫ��
	bool isEmpty();//�ж��Ƿ�ջ��
	void MakeEmpty();//���
	friend ostream& operator<<(ostream& cout, LinkStack &ls);//����<<
	
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
	printf("********1.��ջ    		2.��ջ*********\n");
	printf("********3.�õ�ջ��Ԫ�� 	4.��ӡ*********\n");
	printf("********5.�ж�ջ��    	6.�˳�     *********\n");
}
int main()
{
	LinkStack ls; int choice;
	int a;
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
		scanf("%d", &choice);
		if (choice == 6) break;
		switch (choice)
		{
		case 1:
			cout << "��������ջ����:" << endl;
			cin >> a;
			if(ls.Push(a)) cout<<" ��ջ�ɹ�"<<endl;
			cout << "��ǰջ������Ϊ:" << ls << endl;
			break;
		case 2:
			if (ls.Pop()) cout << " ��ջ�ɹ�" << endl;
			else { cout << "ʧ��" << endl; }
			cout << "��ǰջ������Ϊ:" << ls << endl;
			break;
		case 3:
			ls.getTop(a);
			cout << "ջ��Ԫ��Ϊ:" <<a<< endl;
			break;
		case 4:
			cout << "��ջ������Ϊ:" << endl;
			cout << ls << endl;
			break;
		case 5:
			if (ls.isEmpty()) cout << " ��ǰջΪ��" << endl;
			else cout << "ջ��Ϊ��" << endl;
			break;
		default:
			break;
		}

	}
}
