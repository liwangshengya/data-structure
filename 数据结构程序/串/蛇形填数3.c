
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max 100

//k=1  ����      �ڵ�һ�� k=2 ���һ�� k=4
//k=2	������	�ڵ�һ��  k=3  ���һ��k=1  ����λ�� k=2
//k=3	����	�ڵ�һ�� k=4   ���һ�� k=2
//k=4	������ 	��һ�� k=1  ���һ�� k=3  ���� k=4  

//Ҫע�����½Ǻ����Ͻ� ��ʱ��һ�к����һ���������ֽ���  ���һ��,��һ��


void display(int n)
{
	int a[max][max] = { 0 };
	int x,y;
	x = 0; y = 0;
	int count = 1;
	int k = 1;
	a[x][y] = 1;
	while (count <= n * n)
	{
		if (k == 1)
		{
			a[x][++y] = ++count;
			if (x== 0) k = 2;
			else k = 4;
		}
		if (k == 2)
		{
			a[++x][--y] = ++count;
			if (y == 0&&x!=n-1) k = 3;//
			else if (x == n - 1) k = 1;
			else k = 2;
		}
		if (k == 3)
		{
			a[++x][y] = ++count;
			if (y == 0) k = 4;
			else k = 2;
		}
		if (k == 4)
		{
			a[--x][++y] = ++count;
			if (x ==0&&y!=n-1) k = 1;
			else if (y == n - 1) k = 3;
			else k = 4;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	printf("����������n:");
	int n;
	scanf("%d", &n);
	display(n);
	return 0;
}