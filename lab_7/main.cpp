#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <queue>
#include <string.h>

using namespace std;

int** gen_m_v(int** M, int n)
{
	int i, j, z = 1;
	M = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		M[i] = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	
	for (i = 0; i < n; i++)
	{
		M[i][i] = 0;
		for (j = z; j < n; j++)
		{
			if (rand() % 100 > 50) M[i][j] = 0; else M[i][j] = 1;
			if (M[i][j] = 1) 
			{
				M[i][j] = rand() % 10;
				M[j][i] = M[i][j];
			}
		}
		z++;
	}
	return M;
}


void print(int** M, int n)
{
	int i, j;

	printf("V matrice\n");
	for (i = 0; i < n; i++) printf(" x%d", i);
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%*d", 3, M[i][j]);
		}
	}
}

void ob_m_1(int** M, int n, int k, int* m)
{
	queue <int> Q;
	int i, j = k;

	Q.push(k);
	m[k] = 0;
	while (!Q.empty())
	{
		j = Q.front();
		printf("%*d", 3, j);
		Q.pop();
		for (i = 0; i < n; i++)
		{
			if (M[j][i] > 0 && m[i] > m[j] + M[j][i])
			{
				m[i] = m[j] + M[j][i];
				Q.push(i);
			}
		}
	}
}
void hod1(int** M, int n, int k)
{
	int i, * m;

	m = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		m[i] = INT_MAX;
	}
	ob_m_1(M, n, k, m);
	for (i = 0; i < n; i++)
		if (m[i] == INT_MAX)
			printf("\nRast do %d net", i);
		else
			printf("\nRast do %d = %d", i, m[i]);
	free(m);
}

void main()
{
	int** M = NULL, n, k, i;
	printf("Vvedite razmer grafa:");
	scanf("%d", &n);

	M = gen_m_v(M, n);
	print(M, n);
	printf("\n\nVvedite noner vershini:");
	scanf("%d", &k);
	hod1(M, n, k);

	for (i = 0; i < n; i++)
	{
		free(M[i]);
	}
	free(M);
}
