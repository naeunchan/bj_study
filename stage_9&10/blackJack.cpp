#include <iostream>
using namespace std;

int main(void)
{
	int N, M, i, j, k, max = 0;
	cin >> N >> M;
	int *arr = new int[N];
	for (i = 0; i < N; i++)
		cin >> arr[i];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (j != i)
			{
				for (k = 0; k < N - 2; k++)
				{
					if (k != i && k != j)
					{
						if (arr[i] + arr[j] + arr[k] <= M && max < arr[i] + arr[j] + arr[k])
							max = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
	}
	cout << max;
	delete[] arr;
	return 0;
}