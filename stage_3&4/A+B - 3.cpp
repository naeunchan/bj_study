#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	int * a = (int *)malloc(sizeof(int) * T);
	int * b = (int *)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < T; i++)
		cout << a[i] + b[i] << endl;
	free(a);
	free(b);
	return 0;
}