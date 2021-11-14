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
	//int k = 0;
	while (i < lens && j < lent)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++; j++;
		//	k++;
		}
		else
		{
			j = next[j];
	//		k++;
		}
	}
	//cout << i << "   " << j << endl;
	//cout << "KMP:j移动的次数:" <<k<< endl;
	if (j == lent) return i - j + 1;
	else return -1;
}




int main()
{
	char* s = new char[1000000];
	char* t = new char[1000000];
	int* next = new int[1000000];
	int n;int m;
	cout<<"请输入同学的人数:";
	cin>>n;
	for(int i=0;i<n;i++)  cin>>s[i];
	cout<<"请输入整数m:";
	cin>>m;
	for(int i=0;i<m;i++) cin>>t[i];

	
	
	get_next(t, next);
	//cout << next[0] << "  " << next[1] << " " << next[2] << endl;
	int k=KMF(s,t,next);
	if(k==-1) cout<<k<<endl;
	else 
	{
		cout<<k<<" "<<k+m-1<<endl;
	}
}