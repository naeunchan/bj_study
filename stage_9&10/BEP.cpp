#include <iostream>
using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;

	if ((C - B) <= 0)
		cout << -1;
	else
		cout << A / (C - B) + 1 << endl;
	return 0;
}