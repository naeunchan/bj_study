#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	int a = 1, b = 1, i = 1;
	int * x = (int *)malloc(sizeof(int));

	while (a != 0 && b != 0)
	{
		cin >> a >> b;
		x[i - 1] = a + b;
		x = (int *)realloc(x, sizeof(int) * ++i);
	}
	for (int n = 0; n < i - 2; n++)
		cout << x[n] << endl;
	free(x);
	return 0;
}