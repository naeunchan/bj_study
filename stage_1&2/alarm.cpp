#include <iostream>
using namespace std;

int main(void)
{
	int h, m, a, b;
	cin >> h >> m;

	if ((m - 45) < 0)
	{
		h -= 1;
		m = m + 15;
	}
	else
		m -= 45;
	if (h < 0)
		h = 23;
	cout << h << " " << m;

	return 0;
}