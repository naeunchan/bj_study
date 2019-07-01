#include <iostream>

using namespace std;

int main(void)
{
	int arr[8];
	int a = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] == i + 1)
			a++;
		else if (arr[i] == 8 - i)
			a--;
	}
	if (a == 8)
		cout << "ascending" << endl;
	else if (a == -8)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;
	return 0;
}