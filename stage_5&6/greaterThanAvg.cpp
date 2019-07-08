#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int C, N, i, j, k;

	scanf("%d", &C);
	int **arr = (int **)malloc(sizeof(int *) * C);
	double * a = (double *)malloc(sizeof(double) * C);

	for (i = 0; i < C; i++)
	{
		k = 0;
		scanf("%d", &N);
		arr[i] = (int *)malloc(sizeof(int) * (N + 1));
		arr[i][0] = N;
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
			k += (double)arr[i][j];
		}
		a[i] = (double)k / (double)arr[i][0];
		while (getchar() != '\n')
			break;
	}
	for (i = 0; i < C; i++)
	{
		k = 0;
		for (j = 1; j <= arr[i][0]; j++)
		{
			if (a[i] < arr[i][j])
				k++;
		}
		printf("%.3f%%\n", (double)k / (double)arr[i][0] * 100);
	}
	for (i = 0; i < C; i++)
		free(arr[i]);
	free(arr);
	free(a);

	return 0;
}