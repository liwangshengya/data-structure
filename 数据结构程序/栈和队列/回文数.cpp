
//������
#include<iostream>
using namespace std;
#include<string.h>
const int MaxSize=50;
class Stack
{
public: 
	Stack();
	Stack(int s);
	~Stack();
	bool Push(char ch);//��ջ
	bool Pop();//��ջ
	char getTop();//�õ�ջ��Ԫ��
	bool isEmpty();//�ж��Ƿ�Ϊ��ջ
	bool isFull();//�ж��Ƿ�ջ��
private:
	char *data;
	int size;
	int top;
};
Stack::Stack()
{
	size=MaxSize;
	top=-1;
	data=new char[size];
}
Stack::Stack(int s)
{
	size=s;
	top=-1;
	data=new char[size];
}

bool Stack::Push(char ch)
{
	if(isFull()) { return false;}
	data[++top]=ch;
	return true;
}

bool Stack::Pop()
{
	if(isEmpty()){return false; }
	data[top--];
	return true;
}
char Stack::getTop()
{
	if(isEmpty()) exit(-1);
	char ch;
	ch=data[top];
	return ch;
}

bool Stack::isEmpty()
{
	if(top==-1) return true;
	else return false;
}
bool Stack::isFull()
{
	if(top==size-1) return true;
	else return false;
}
Stack::~Stack()
{
	delete []data;
	top=-1;
}

void split(Stack &st,char str[],int n)
{
	for(int i=0;i<n;i++)
	{
		st.Push(str[i]);
	}
}

int jiou(int n)
{
	if(n%2==0) return 0;
	else return 1;
}

int main()
{
	Stack st(30);
	char str[200];
	int count=0;
	int n;
	cout<<"������һ���ַ���:"<<endl;
	cin>>str;
	n=strlen(str);
	split(st,str,n/2);
	for(int i=0;i<n/2;i++)
	{
		if(st.getTop()!=str[n/2+jiou(n)+i])
		{
			count++;
		}
		st.Pop();
	}
	if(count) cout<<"���ַ������ǻ�����"<<endl;
	else cout<<"���ַ����ǻ�����"<<endl;

}