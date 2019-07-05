#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T, n, i, j, k, res = 0, a, b;
	bool * arr = (bool *)calloc(10001, sizeof(bool));
	arr[0] = arr[1] = true;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		res = 99999;
		scanf("%d", &n);
		for (j = 2; j * j <= n; j++)
		{
			if (!arr[j])
				for (k = j * 2; k <= n; k += j)
					arr[k] = true;
		}
		for (a = b = n / 2; a <= n; a--, b++)
		{
			if (!arr[a] && !arr[b])
			{
				printf("%d %d\n", a, b);
				break;
			}
		}

	}
	free(arr);
	return 0;
}