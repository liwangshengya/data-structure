#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max 100
void display(int n)
{
	int count = 1;
	int x, y;
	x = 0; y = n - 1;
	int a[max][max] = { 0 };
	a[x][y] = 1;
	while (count < n * n)
	{
		while (x + 1 < n && a[x + 1][y] == 0) a[++x][y] = ++count;
		while (y - 1 >= 0 && a[x][y - 1] == 0) a[x][--y] = ++count;
		while (x - 1 >= 0 && a[x - 1][y] == 0) a[--x][y] = ++count;
		while (y + 1 <=n && a[x][y + 1] == 0)   a[x][++y] = ++count;
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
	printf("ÇëÊäÈëÕûÊýn:");
	int n;
	scanf("%d", &n);
	display(n);
	return 0;
}