#include <iostream>
using namespace std;

int main(void)
{
	int X, cnt = 1, sum = 1;
	int i, a = 1, b = 1;
	cin >> X;

	while (1)
	{
		if ((cnt % 2) == 0)
		{
			for (i = 0; i < cnt; i++)
			{
				a = i + 1;
				b = cnt - i;
				if (sum == X)
				{
					cout << a << "/" << b;
					return 0;
				}
				sum++;
			}
		}
		else
		{
			for (i = 0; i < cnt; i++)
			{
				a = cnt - i;
				b = i + 1;
				if (sum == X)
				{
					cout << a << "/" << b;
					return 0;
				}
				sum++;
			}
		}
		cnt++;
	}

	return 0;
}