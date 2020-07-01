#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_CTYPE, "");
	int n,i,j,m,**a,sum=0,k,l;
	printf("¬ведите кол-во строк в матрице:");
	scanf("%d", &n);
	printf("¬ведите кол-во столбцов в матрице:");
	scanf("%d", &m);
	a = new int *[n];
	for (i = 0; i < n; i++)
		a[i] = new int[m];
	for (i = 0; i < n; i++) {
		printf("¬ведите "); printf("%d", i + 1); printf("-ую строку массива:");
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n - 1; i++)
	{
		k = 0;
		for (j = 0; j < m; j++)
		{
			k += a[i][j] * a[i + 1][j];
		}
		if (k > sum)
		{
			sum = k;
			l = i;
		}
	}
	printf("ћаксимальное скал€рное произведение пар строк: %d",sum);
	printf("\n");
	printf("ѕара строк с максимальным скал€рным произведением под номерами %d и ", l+1); printf("%d", l + 2);
	_getch();
}