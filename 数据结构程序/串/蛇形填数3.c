
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max 100

//k=1  向右      在第一行 k=2 最后一行 k=4
//k=2	向左下	在第一列  k=3  最后一行k=1  其他位置 k=2
//k=3	向下	在第一列 k=4   最后一列 k=2
//k=4	向右上 	第一行 k=1  最后一列 k=3  其他 k=4  

//要注意左下角和右上角 此时第一列和最后一行条件会又交叉  最后一列,第一行


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
	printf("请输入整数n:");
	int n;
	scanf("%d", &n);
	display(n);
	return 0;
}