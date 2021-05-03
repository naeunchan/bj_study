#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;

	vector<int> v(N);

	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	cin >> M;

	for(int i = 0; i < M; i++){
		int m;
		int front = 0;
		int back = v.size();
		bool check = false;

		cin >> m;

		while(front <= back){
			int mid = (front + back) / 2;
			
			if(v[mid] == m){
				check = true;
				break;
			}

			if(m < v[mid]){
				back = mid - 1;
			}
			else{
				front = mid + 1;
			}
		}

		if(check){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}