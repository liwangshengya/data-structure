
//回文数
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
	bool Push(char ch);//入栈
	bool Pop();//出栈
	char getTop();//得到栈顶元素
	bool isEmpty();//判断是否为空栈
	bool isFull();//判断是否栈满
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
	cout<<"请输入一段字符串:"<<endl;
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
	if(count) cout<<"该字符串不是回文数"<<endl;
	else cout<<"该字符串是回文数"<<endl;

}