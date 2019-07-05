#include <stdio.h>

int rec(int k, int n);

int main(void)
{
	int T, k, n, num = 0;
	int apt[15][14] = { 0, };
	int i, j, z;

	for (i = 0; i < 14; i++)
	{
		apt[0][i] = i + 1;
	}

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", rec(k, n));
	}
	return 0;
}

int rec(int k, int n)
{
	int num = 0;
	if (k == 0)
		return n;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			num += rec(k - 1, i);
		}
		return num;
	}
}