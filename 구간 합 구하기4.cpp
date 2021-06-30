#include <iostream>
#include <vector>

using namespace std;

vector<long long> numbers(100001, 0);
vector<long long> sums(100001, 0);
int N = 0;
int M = 0;

long long sum(int i){
	long long res = 0;

	while(i > 0){
		res += sums[i];
		i -= (i & -i);
	}

	return res;
}

void update(int i, long long replace){
	while(i <= N){
		sums[i] += replace;
		i += (i & -i);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for(int i = 1; i <= N; i++){
		cin >> numbers[i];
		update(i, numbers[i]);
	}

	while(M--){
		int i, j;

		cin >> i >> j;
		cout << sum(j) - sum(i - 1) << "\n";
	}

	return 0;
}