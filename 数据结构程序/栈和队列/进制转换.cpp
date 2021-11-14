//进制转换
#include<iostream>
using namespace std;
#include<string.h>
#include<string>
const int MaxSize = 10000;
void decToother(int temp, int b);//十进制转换为任意进制
int OrtherTodec(int a, char str[]);//任意进制转十进制

int main()
{
	char str[MaxSize];//带转换的内容
	int a;//当前进制
	int b;//目标进制
	cout << "请输入分别输入当前进制 ,带转换数字 ,目标进制:" << endl;
	cin >> a >> str >> b;
	int temp = OrtherTodec(a, str);
	//cout << temp;
	decToother(temp, b);



}
int OrtherTodec(int a, char str[])
{
	int temp = 0;//保存十进制值
	int c = 1;//初始化权值为1
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		int x;//存放当前位数字
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			x = str[i] - 'A' + 10;//字母A-Z表示整数10-35
		}//
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			x = str[i] - 'a' + 36;//字母a-z表示整数36-61
		}
		else x = str[i] - '0';
		temp = temp + x * c;//累加各个位上的值
		c = c * a;//更新权值
	}
	return temp;
}

void  decToother(int temp, int b)
{
	int i = 0;
	int j = 0;
	int s[MaxSize] = { 0 };
	char str[MaxSize];
	while (temp)
	{
		s[i] = temp % b;
		temp = temp / b;
		i++;
	}//十进制转换为目标进制,结果存放到数组s中
	for (i = i ; i > 0; i--)
	{
		if (s[i-1] > 9 && s[i-1] <= 35)
		{
			str[j] = (char)(s[i-1] + 55);//A的ascll编码值为65,其十进制数为10
			//故 'A'=65-10=55
		}
		else if (s[i-1] > 35 && s[i-1] <= 61)
		{
			str[j] = (char)(s[i-1] + 61);//a的ascall编码值为97,97-36=61
		}
		else str[j] = (char)(s[i-1]+48);//0的ascall编码值为48
		j++;
	}
	cout << "该数字转换后的内容为:" << endl;
	for (int  i = 0; i <= j; i++)
	{
		cout << str[i];
	}
	cout << endl;
}
