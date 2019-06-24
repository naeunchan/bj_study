#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, x, i;

	scanf("%d %d", &N, &x);
	int *arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		while (getchar() != '\n')
			break;
	}
	for (i = 0; i < N; i++)
	{
		if (arr[i] < x)
			printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}