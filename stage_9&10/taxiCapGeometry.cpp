#include <iostream>
#define PI  3.141592653589793238462643383279502884197169
using namespace std;

int main(void)
{
	double R;

	cin >> R;
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << R * R * PI << endl;
	cout << 2.0 * R * R << endl;
	return 0;

}