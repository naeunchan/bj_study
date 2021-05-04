#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
    long long ans = 0;
	long long front = 1, back = 0, mid = 0;
	vector<long long> v;

	cin >> K >> N;

	for(int i = 0; i < K; i++){
		long long n;
		cin >> n;

		v.push_back(n);
	}

	sort(v.begin(), v.end());

	back = v.back();

	while(front <= back){
		int count = 0;

		mid = (front + back) / 2;

		for(int i = 0; i < K; i++){
			count += v[i] / mid;
		}

		if(count >= N){
			ans = ans < mid ? mid : ans;
			front = mid + 1;
		}
		else if(count < N){
			back = mid - 1;
		}
	}

	cout << ans;

	return 0;
}