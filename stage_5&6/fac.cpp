#include <iostream>
using namespace std;

int fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main(void)
{
	int n, i;

	cin >> n;

	cout << fac(n);
	return 0;
}