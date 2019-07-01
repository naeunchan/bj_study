#include <iostream>

using namespace std;

int main(void)
{
	int arr[42] = { 0, };
	int cnt = 0;
	int n;

	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		arr[n % 42] = 1;
	}
	for (int i = 0; i < 42; i++)
		cnt += arr[i];
	cout << cnt;
	return 0;

}