#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	int n, i, sum, add;
	char arr[80];
	cin >> n;

	for (i = 0; i < n; i++)
	{
		sum = 0;
		add = 1;
		scanf("%s", &arr);
		for (int j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == 'O')
			{
				sum += add;
				add++;
			}
			if (arr[j] == 'X')
				add = 1;
		}
		cout << sum << endl;
	}
}