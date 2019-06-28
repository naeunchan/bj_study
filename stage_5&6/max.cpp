#include <stdio.h>

int main(void)
{
	int n;
	int a[9];
	int max = 0, i, j;

	for (i = 0; i < 9; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < 9; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			j = i;
		}
	}
	printf("%d\n%d", max, j + 1);
	return 0;

}