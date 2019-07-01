#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N;
	int min = INT_MAX, max = INT_MIN;
	cin >> N;
	int * arr = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	cout << min << " " << max << endl;
	free(arr);
	return 0;
}