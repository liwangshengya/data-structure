#include<iostream>
using namespace std;
#include<string.h>
void get_next(char t[], int next[])
{
	int i = 0;
	next[i] = -1;
	int j = -1;
	while (i<strlen(t))
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
	
	while (i < lens && j < lent)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++; j++;
			
		}
		else
		{
			j = next[j];
			
		}
	}
	//cout << i << "   " << j << endl;
	
	if (j == lent) return i - j + 1;
	else return -1;
}
int BF(char s[], char t[])
{
	int i, j;
	i = 0; j = 0;
	
	while (s[i]!='\0' && t[j]!='\0')
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
			
		}
		else
		{
			i = i - j + 1;
			j = 0;
			
		}
	}
	if (t[j] == '\0') return i - j+1;
	else return -1;
}



int main()
{
	char* s = new char[1000000];
	char* t = new char[1000000];
	int* next = new int[1000000];
	int k;
	while(1){
		cout << "input(CRTL+C结束程序):" << endl;
		cin >> s;
		cin >> t;
		get_next(t, next);
		k=KMF(s, t, next);
		if(k==-1)cout<<k<<endl;
		else cout<<"s2在s1的位置为:"<<k<<endl;
	}
	
	
	
}