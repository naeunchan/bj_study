#include <stdio.h>

void hanoi(int f, int s, int t, int n)
{
	if (n == 1)
		printf("%d %d\n", f, t);
	else
	{
		hanoi(f, t, s, n - 1);
		printf("%d %d\n", f, t);
		hanoi(s, f, t, n - 1);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(1, 2, 3, n);

	return 0;
}