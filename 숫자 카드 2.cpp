#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<int, int> m;

	cin >> N;

	for(int i = 0; i < N; i++){
		int n;
		cin >> n;

		m[n]++;
	}

	cin >> M;

	for(int i = 0; i < M; i++){
		int n;
		cin >> n;

		cout << m[n] << " ";
	}
	
	return 0;
}