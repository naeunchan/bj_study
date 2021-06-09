#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> ans;

	cin >> N;

	vector<long long> v(N, 0);

	for(int i = 0; i < N; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cin >> M;

	for(int i = 0; i < M; i++){
		long long n;
		int front = 0, back = N;
		bool check = false;

		cin >> n;

		while(front <= back){
			int mid = (front + back) / 2;

			if(v[mid] == n){
				ans.push_back(1);
				check = true;
				break;
			}
			else if(v[mid] < n){
				front = mid + 1;
			}
			else{
				back = mid - 1;
			}
		}

		if(!check){
			ans.push_back(0);
		}
	}

	for(int i = 0; i < M; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}