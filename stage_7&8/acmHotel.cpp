#include <stdio.h>

int main(void)
{
	int H, W, N, T, a, b;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		if ((N % H) == 0)
		{
			a = H;
			b = N / H;
		}
		else
		{
			a = N % H;
			b = N / H + 1;
		}
		printf("%d\n", 100 * a + b);
	}

	return 0;
}