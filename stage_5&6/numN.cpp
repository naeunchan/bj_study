#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c;
	int num[10] = {};
	int tmp[9];
	int res;

	cin >> a >> b >> c;
	res = a * b * c;
	for (int i = 0; i < 9; i++)
		tmp[i] = -1;
	for (int i = 0; i < 9; i++)
	{
		tmp[i] = res % 10;
		res /= 10;
		if (res == 0)
			break;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tmp[i] == j)
				num[j] += 1;
		}
	}

	for (int i = 0; i < 10; i++)
		cout << num[i] << endl;
	return 0;

}