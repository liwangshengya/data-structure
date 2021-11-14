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
				printf("出局的猴子为:%d\n",a[pos]);
				a[pos]=0;//猴子出局
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
			printf("最后的为%d\n",a[i]);
	}
	
}
int main()
{
	int m,n;//总数目与报数的数
	printf("请输入总人数和报的数:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
}