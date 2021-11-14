#include<stdio.h>
void yuesefu(int m,int n)
{
	int a[m];
	for(int i=0;i<m;i++)
	{
		a[i]=i+1;
	}
	a[m-1]=0;
	int count=1;
	int pirror,pos;//以前一后
	pirror=n-1;//指向最后一个结点
	pos=0;//指向第一个结点
	int number=m;
	while(number>1)
	{
		if(count!=n)
		{
			pirror=pos;//分别向后移动
			pos=a[pos];
			count++;
		}
		else
		{
			a[pirror]=a[pos];//第pos个出局,将其摘出
			printf(" 出局的为:%d\n",pos+1);
			a[pos]=-1;
			count=1;
			number--;
			pos=a[pirror];
		}
	}
	printf("最后的为%d\n",pos+1);
}
int main()
{
	int m,n;//总数目与报数的数
	printf("请输入总人数和报的数:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
	return 0;
}