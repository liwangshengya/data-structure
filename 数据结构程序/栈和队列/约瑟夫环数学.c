#include<stdio.h>
int yuesefu(int m,int n)//�ݹ�
{
	if(m==1)
		return 1;
	else 
		return (yuesefu(m-1,n)+n)%m;
}

int yuesefu1(int m,int n)//ֱ�����
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
	int m,n;//����Ŀ�뱨������
	printf("�������������ͱ�����:");
	scanf("%d%d",&m,&n);
	printf("������Ϊ%d\n",yuesefu(m,n));
	printf("������Ϊ%d\n",yuesefu1(m,n));
}