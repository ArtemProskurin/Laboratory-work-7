#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_CTYPE, "");
	int n,i,j,m,**a,sum=0,k,l;
	printf("������� ���-�� ����� � �������:");
	scanf("%d", &n);
	printf("������� ���-�� �������� � �������:");
	scanf("%d", &m);
	a = new int *[n];
	for (i = 0; i < n; i++)
		a[i] = new int[m];
	for (i = 0; i < n; i++) {
		printf("������� "); printf("%d", i + 1); printf("-�� ������ �������:");
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
	
	printf("%d",sum);
	_getch();
}