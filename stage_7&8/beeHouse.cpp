#include <iostream>
using namespace std;

int main(void)
{
	int N, i = 1, sum = 1;

	cin >> N;

	while (1)
	{
		if (N == 1)
		{
			cout << i;
			return 0;
		}
		else
		{
			sum += 6 * i;
			if (N <= sum)
			{
				cout << i + 1;
				return 0;
			}
			i++;
		}
	}
	return 0;
}