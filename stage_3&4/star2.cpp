#include <stdio.h>

int main(void)
{
	int n, i, j, k;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
			printf(" ");

		for (k = j; k <= n; k++)
			printf("*");
		printf("\n");
	}
	return 0;
}