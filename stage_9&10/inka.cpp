#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main(void)
{
	int T, x, y, M, N, cnt = 0;
	int L;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		L = lcm(M, N);
		while (1)
		{
			if (x > L || (x - 1) % N + 1 == y)
				break;
			x += M;
		}
		if (x > L)
			printf("-1\n");
		else
			printf("%d\n", x);
	}

}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}