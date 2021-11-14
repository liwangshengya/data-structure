
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define max 100
void display(int n)
{
	int a[max][max] = { 0 };
	int x, y;
	int count = 1;
	x = 0; y = 0;
	a[x][y] = 1;
	while (count < (n * (n + 1) / 2))
	{
		while (y + 1 < n && a[x][y + 1] == 0)  a[x][++y] = ++count;
		printf("x=%d,y=%d\n", x, y);
		while (x + 1 <n && a[x + 1][y - 1] == 0) {  a[++x][--y] = ++count;  }
		printf("x=%d,y=%d\n", x, y);
		while (x - 1 >= 0 && a[x - 1][y] == 0)  a[--x][y] = ++count;
		printf("x=%d,y=%d\n", x, y);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
				printf("%d	", a[i][j]);
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
