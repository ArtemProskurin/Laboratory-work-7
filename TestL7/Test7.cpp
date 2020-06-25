#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
int main() {
	setlocale(LC_CTYPE, "");
	int i, j, a[N][N],sum=0,y,u,k;
	FILE *fp;
	fp = fopen("in.txt", "r");
	if (fp) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				fscanf(fp, "%d", &a[i][j]);
			}
		}
		fclose(fp);
	}
	y = 0;
	u = 0 ;
		for (i = 0; i < 1; i++)
		{
			for (int j = 0; j < N; ++j)
			{
				y += a[i][j];
			}
		}
		for (int j = 4; j < N; ++j)
		{
			for (int i = 0; i < N; i++)
			{
				u += a[i][j];
			}
		}
	sum = y + u;
	printf("Sum=%d", sum);
	_getch();
}