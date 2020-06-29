#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define N 5
void input_matr(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++) {
		printf("Введите "); printf("%d", i + 1); printf("-ую строку массива:");
		for (j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void input_matr_file(int a[N][N]) {
	int i, j;
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
}

float y_rec(float *x, int y, bool check, int index)
{
	int dc1, g;
	double cc1;
	if (check == 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (x[index] > x[i])
			{
				index = i;
			}
		}
		check = 1;
	}
	if (check == 1)
	{
		if (index != N - 2)
		{
			dc1 = modf(x[index + 1], &cc1);
			g = static_cast<int>(cc1);
			if (g % 2 == 0)
			{
				y = x[index + 1] * y_rec(x, y, check, index + 1);
				return y;
			}
			else
			{
				y = y_rec(x, y, check, index + 1);
				return y;
			}
		}
		else if (index == N - 2)
		{
			{
				dc1 = modf(x[index + 1], &cc1);
				g = static_cast<int>(cc1);
				if (g % 2 == 0)
				{
					y = x[index + 1];
					return y;
				}
				else
				{
					return y = 1;
				}
			}
		}
	}
	return y;
}
float *mas_x(int(*a)[N], float *x,
	void(*pfunc)(int[N][N]))
{
	int i, j, b = 0, y = 0;
	float sum;
	pfunc(a);
	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j < N; ++j)
		{
			sum += a[i][j];
		}
		b = j - i - 1;
		for (j = N - 1; j >= 0; j--)
		{
			if (j != i)
			{
				sum += a[j][b];
			}
		}
		x[i] = sum / (N * 2 - 1);
	}
	y = y_rec(x, y, 0, 0);
	if (y == 1)
	{
		printf("Все элементы нечетные после первого минимального!!!!");
		printf("\n");
	}
	else
	{
		printf("Y=%f", y);
		printf("\n");
	}
	return x;
}

void output(const float x[], const int a[N][N])
{
	int i, j;
	FILE*fp;
	fp = fopen("out.txt", "w");
	printf("Исходная матрица:\n");
	fprintf(fp, "Исходная матрица:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%5d", a[i][j]);
			fprintf(fp, "%5d", a[i][j]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}

	printf("Результирующий массив:\n");
	fprintf(fp, "Результирующий массив:\n");
	for (i = 0; i < N; i++) {
		printf("%f", x[i]);
		fprintf(fp, "%f", x[i]);
		printf(" ");
		fprintf(fp, " ");
	}
	fclose(fp);
}
int main()
{
	setlocale(LC_CTYPE, "");
	int a[N][N], c;
	float  x[N];
	void(*pfunc)(int[N][N]);
	{
		printf("Ввод матрицы:\n1 - с клавиатуры\n2- Из файла\n");
		scanf("%d", &c);
	}
	while (c != 1 && c != 2);
	switch (c)
	{
	case 1: pfunc = &input_matr;
		break;
	case 2: pfunc = &input_matr_file;
	}
	output(mas_x(a, x, pfunc), a);
	_getch();
}