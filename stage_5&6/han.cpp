#include <iostream>
using namespace std;

int han(int n)
{
	int i, res = 0;
	int a, b, c;

	if (n < 100)
	{
		return n;
	}
	else
	{
		res = 99;
		for (i = 100; i <= n; i++)
		{
			a = i / 100;
			b = (i / 10) % 10;
			c = i % 10;

			if ((a - b) == (b - c))
				res++;
		}
		return res;
	}
}

int main(void)
{
	int n, i;

	cin >> n;

	printf("%d\n", han(n));
	return 0;
}