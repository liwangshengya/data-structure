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
	int pirror,pos;//��ǰһ��
	pirror=n-1;//ָ�����һ�����
	pos=0;//ָ���һ�����
	int number=m;
	while(number>1)
	{
		if(count!=n)
		{
			pirror=pos;//�ֱ�����ƶ�
			pos=a[pos];
			count++;
		}
		else
		{
			a[pirror]=a[pos];//��pos������,����ժ��
			printf(" ���ֵ�Ϊ:%d\n",pos+1);
			a[pos]=-1;
			count=1;
			number--;
			pos=a[pirror];
		}
	}
	printf("����Ϊ%d\n",pos+1);
}
int main()
{
	int m,n;//����Ŀ�뱨������
	printf("�������������ͱ�����:");
	scanf("%d%d",&m,&n);
	yuesefu(m,n);
	return 0;
}