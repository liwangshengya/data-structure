//����ת��
#include<iostream>
using namespace std;
#include<string.h>
#include<string>
const int MaxSize = 10000;
void decToother(int temp, int b);//ʮ����ת��Ϊ�������
int OrtherTodec(int a, char str[]);//�������תʮ����

int main()
{
	char str[MaxSize];//��ת��������
	int a;//��ǰ����
	int b;//Ŀ�����
	cout << "������ֱ����뵱ǰ���� ,��ת������ ,Ŀ�����:" << endl;
	cin >> a >> str >> b;
	int temp = OrtherTodec(a, str);
	//cout << temp;
	decToother(temp, b);



}
int OrtherTodec(int a, char str[])
{
	int temp = 0;//����ʮ����ֵ
	int c = 1;//��ʼ��ȨֵΪ1
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		int x;//��ŵ�ǰλ����
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			x = str[i] - 'A' + 10;//��ĸA-Z��ʾ����10-35
		}//
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			x = str[i] - 'a' + 36;//��ĸa-z��ʾ����36-61
		}
		else x = str[i] - '0';
		temp = temp + x * c;//�ۼӸ���λ�ϵ�ֵ
		c = c * a;//����Ȩֵ
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
	}//ʮ����ת��ΪĿ�����,�����ŵ�����s��
	for (i = i ; i > 0; i--)
	{
		if (s[i-1] > 9 && s[i-1] <= 35)
		{
			str[j] = (char)(s[i-1] + 55);//A��ascll����ֵΪ65,��ʮ������Ϊ10
			//�� 'A'=65-10=55
		}
		else if (s[i-1] > 35 && s[i-1] <= 61)
		{
			str[j] = (char)(s[i-1] + 61);//a��ascall����ֵΪ97,97-36=61
		}
		else str[j] = (char)(s[i-1]+48);//0��ascall����ֵΪ48
		j++;
	}
	cout << "������ת���������Ϊ:" << endl;
	for (int  i = 0; i <= j; i++)
	{
		cout << str[i];
	}
	cout << endl;
}
