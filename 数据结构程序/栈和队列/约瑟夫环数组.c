#include<stdio.h>
void yuesefu(int m,int n)
{
	int a[m];
	int i;
	for(int i=0;i<m;i++)
	{
		a[i]=i+1;
	}
	i=1;
	int pos=0;
	int num=m;
	while(num>1)
	{
		if(a[pos]>0)
		{
			if(i==n)
			{
				printf("���ֵĺ���Ϊ:%d\n",a[pos]);
				a[pos]=0;//���ӳ���
				num--;
				pos=(pos+1)%m;
				i=1;
			}
			else{
				i++;
				pos=(pos+1)%m;
			}
		}
		else
	        pos=(pos+1)%m;
	}
	for(int i=0;i<m;i++)
	{
		if(a[i]!=0)
			printf("����Ϊ%d\n",a[i]);
	}
	
}
int main()
{
	int m,n;//����Ŀ�뱨������
	printf("�������������ͱ�����:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
}