#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int M, i, j;
	bool *arr;
	while (1)
	{
		int cnt = 0;
		scanf("%d", &M);
		if (M == 0)
			break;
		else
		{
			arr = (bool *)calloc((2 * M) + 1, sizeof(bool));
			arr[0] = arr[1] = true;

			for (i = 2; i * i <= 2 * M; i++)
			{
				if (!arr[i])
					for (j = i * 2; j <= 2 * M; j += i)
						arr[j] = true;
			}
			for (i = M + 1; i <= 2 * M; i++)
				if (arr[i] == false)
					cnt++;
			printf("%d\n", cnt);
			free(arr);
		}
	}
	return 0;
}