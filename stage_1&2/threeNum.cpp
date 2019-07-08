#include <stdio.h>

int main(void)
{
	int a[3];
	int tmp;

	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	for (int i = 2; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	printf("%d\n", a[1]);


	return 0;
}