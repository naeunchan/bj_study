#include <iostream>
#define INF 99999
using namespace std;

int main(void)
{
	int M, N, i, j;
	int min, res, cnt;
	cin >> M;
	cin >> N;
	cnt = 0;
	res = 0;
	min = INF;
	for (i = M; i <= N; i++)
	{
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
		{
			cnt++;
			res += i;
			if (min > i)
				min = i;
		}
	}
	if (!cnt)
		cout << -1 << endl;
	else
	{
		cout << res << endl;
		cout << min << endl;
	}
	return 0;
}