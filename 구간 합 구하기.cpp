#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
vector<long long> numbers(1000001, 0);
vector<long long> sums(1000001, 0);

long long sum(int i){
	long long res = 0;

	while(i > 0){
		res += sums[i];
		i -= (i & -i);
	}
	
	return res;
}

void update(int i, long long diff){
	while(i <= N){
		sums[i] += diff;
		i += (i & -i);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;

	cin >> N >> M >> K;

	for(int i = 1; i <= N; i++){
		cin >> numbers[i];
		update(i, numbers[i]);
	}

	for(int i = 0; i < M + K; i++){
		long long a, b, c;

		cin >> a >> b >> c;

		if(a == 1){
			long long diff = c - numbers[b];
			numbers[b] = c;
			update(b, diff);
		}
		else{
			cout << sum(c) - sum(b - 1) << "\n";
		}
	}

	return 0;
}