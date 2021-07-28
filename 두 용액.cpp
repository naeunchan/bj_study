#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int N;
  int result = INT_MAX;
  int front = 0, end = 0;
  vector<int> answer(2, 0);

  cin >> N;

  vector<int> v(N, 0);

  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }

  end = N - 1;
  sort(v.begin(), v.end());

  while (front < end)
  {
    int sum = abs(v[front] + v[end]);

    if (sum < result)
    {
      answer[0] = v[front];
      answer[1] = v[end];
      result = sum;
    }

    if (sum == 0)
    {
      break;
    }
    else if (abs(v[front]) < abs(v[end]))
    {
      end--;
    }
    else
    {
      front++;
    }
  }

  sort(answer.begin(), answer.end());

  cout << answer[0] << " " << answer[1];
  return 0;
}