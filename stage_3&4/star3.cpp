#include <stdio.h>

int main(void)
{
	int n, i, j;

	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{
		for (i = n - j; i > 0; i--)
			printf("*");

		printf("\n");
	}
	return 0;
}