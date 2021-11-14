#include<stdio.h>
int yuesefu(int m,int n)//递归
{
	if(m==1)
		return 1;
	else 
		return (yuesefu(m-1,n)+n)%m;
}

int yuesefu1(int m,int n)//直接求解
{
	int s=1;
	for(int i=0;i<m+1;i++)
	{
		s=(s+n)%m;
	}
	return s;
}
int main()
{
	int m,n;//总数目与报数的数
	printf("请输入总人数和报的数:");
	scanf("%d%d",&m,&n);
	printf("最后的人为%d\n",yuesefu(m,n));
	printf("最后的人为%d\n",yuesefu1(m,n));
}