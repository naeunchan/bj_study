#include <iostream>
using namespace std;

int prime(int n);

int main(void)
{
	int N, i, cnt = 0, n;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &n);
		if (prime(n))
			cnt++;
	}
	cout << cnt;
	return 0;
}

int prime(int n)
{
	int cnt = 0;
	if (n == 1)
		return 0;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (n%i == 0)
				cnt++;
		}
		if (cnt == 2)
			return 1;
		else
			return 0;
	}
}
