#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		ll a = 1;
		while (a * a <= (y - x))
			a++;
		a--;

		ll tmp = (y - x) - (a*a);
		tmp = (ll)ceil((double)tmp / (double)a);
		cout << a * 2 - 1 + tmp << endl;
	}
	return 0;
}