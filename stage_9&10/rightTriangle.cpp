#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;
		else
		{
			a = a * a;
			b = b * b;
			c = c * c;

			if (a > b && a > c)
			{
				if (a == b + c)
					cout << "right" << endl;
				else
					cout << "wrong" << endl;
			}
			else if (b > a && b > c)
			{
				if (b == a + c)
					cout << "right" << endl;
				else
					cout << "wrong" << endl;
			}
			else if (c > a && c > b)
			{
				if (c == a + b)
					cout << "right" << endl;
				else
					cout << "wrong" << endl;
			}
		}
	}
	return 0;
}