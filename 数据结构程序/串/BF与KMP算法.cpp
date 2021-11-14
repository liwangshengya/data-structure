#include<iostream>
using namespace std;
#include<string.h>
void get_next(char t[], int next[])
{
	int i = 0;
	next[i] = -1;
	int j = -1;
	while (i < strlen(t))
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else j = next[j];
	}
	/*for (int  i = 0; i < strlen(t); i++)
	{
		cout << next[i] << endl;
	}*/
}
int KMF(char s[], char t[], int next[])
{
	int i = 0, j = 0;
	int lens = strlen(s);
	int lent = strlen(t);
	int k = 0;
	while (i < lens && j < lent)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++; j++;
			k++;
		}
		else
		{
			j = next[j];
			k++;
		}
	}
	//cout << i << "   " << j << endl;
	cout << "KMP:比较的次数:" << k << endl;
	if (j == lent) return i - j + 1;
	else return -1;
}
int BF(char s[], char t[])
{
	int i, j;
	i = 0; j = 0;
	int k = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
			k++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
			k++;
		}
	}
	cout << "BF:比较的次数为" << k << endl;
	if (t[j] == '\0') return i - j + 1;
	else return -1;
}



int main()
{
	char* s = new char[1000000];
	char* t = new char[1000000];
	int* next = new int[1000000];
	cout << "请输入:" << endl;
	cin >> s;
	cin >> t;
	get_next(t, next);
	//cout << next[0] << "  " << next[1] << " " << next[2] << endl;
	cout << BF(s, t) << endl;
	cout << KMF(s, t, next) << endl;
}