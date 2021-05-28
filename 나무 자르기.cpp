#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M, front = 1, back = 0, mid = 0, ans = 0;

	cin >> N >> M;

	vector<long long> v(N, 0);

	for(long long i = 0; i < N; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	back = v.back();

	while(front <= back){
		long long sum = 0;

		mid = (front + back) / 2;

		for(long long i = 0; i < N; i++){
			long long remain = v[i] - mid;

			sum += remain > 0 ? remain : 0;
		}

		if(sum >= M){
			front = mid + 1;
			ans = ans < mid ? mid : ans;
		}
		else{
			back = mid - 1;
		}
	}

	cout << ans;

	return 0;
}