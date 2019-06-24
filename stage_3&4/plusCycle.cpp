#include <stdio.h>

int main(void)
{
	int N, res = 0, tmp = 0, i = 0;
	int arr[2];

	scanf("%d", &N);
	if (N < 10)
	{
		arr[0] = 0;
		arr[1] = N;
	}
	else
	{
		arr[0] = N / 10;
		arr[1] = N % 10;
	}

	while (1)
	{
		tmp = arr[0] + arr[1];
		res = arr[1] * 10 + (tmp % 10);
		i++;
		if (res == N)
			break;
		else
		{
			arr[0] = arr[1];
			arr[1] = tmp % 10;
		}
	}
	printf("%d\n", i);
	return 0;
}