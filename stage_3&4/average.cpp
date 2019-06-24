#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, N, max = 0, x;
	double res = 0;
	scanf("%d", &N);
	int * arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if (x > max)
			max = x;
		arr[i] = x;
		while (getchar() != '\n')
			break;
	}
	for (i = 0; i < N; i++)
		res += ((double)arr[i] / (double)max) * 100;

	printf("%f", res / N);
	free(arr);

	return 0;
}