#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int count = 0;
	cin >> N;

	while (N > 0) {
		if (N % 5 == 0) {
			N -= 5;
			count++;
		}
		else if (N % 3 == 0) {
			N -= 3;
			count++;
		}
		else if (N > 5) {
			N -= 5;
			count++;
		}
		else {
			count = -1;
			break;
		}

	}
	cout << count;
	return 0;
}