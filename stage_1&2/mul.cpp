#include <iostream>
using namespace std;

int main(void)
{
	int a, b, x, y;
	cin >> a;
	cin >> b;
	x = b % 10;
	y = (b % 100) / 10;
	cout << a * x << endl;
	cout << a * y << endl;
	cout << a * (b / 100) << endl;
	cout << a * b << endl;
	return 0;
}