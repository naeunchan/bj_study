#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int M, N, i, j;
	bool *arr;
	scanf("%d %d", &M, &N);
	arr = (bool *)calloc(N + 1, sizeof(bool));
	arr[0] = arr[1] = true;
	for (i = 2; i * i <= N; i++)
	{
		if (!arr[i])
			for (j = i * 2; j <= N; j += i)
				arr[j] = true;
	}
	for (i = M; i <= N; i++)
		if (arr[i] == false)
			printf("%d\n", i);
	free(arr);
	return 0;
}