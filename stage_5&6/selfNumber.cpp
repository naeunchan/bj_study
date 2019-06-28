#include <stdio.h>

void selfNum(bool * arr)
{
	int a, n;

	for (int i = 1; i <= 10000; i++)
	{
		n = a = i;
		while (n > 0)
		{
			a += n % 10;
			n /= 10;
		}
		if (a < 10000)
			arr[a] = true;

	}
}

int main(void)
{
	bool arr[10000] = {};

	selfNum(arr);
	for (int i = 1; i < 10000; i++)
	{
		if (arr[i] != true)
			printf("%d\n", i);
	}
	return 0;
}