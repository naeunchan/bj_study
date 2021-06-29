#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> parent(1001, 0);

int getParent(int x){
	if(parent[x] == x){
		return x;
	}

	return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b){
	a = getParent(a);
	b = getParent(b);

	if(a == b){
		return false;
	}
	else if(a < b){
		parent[b] = a;
		return true;
	}
	else{
		parent[a] = b;
		return true;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	while(T--){
		int N, M, ans = 0;
		parent.assign(1001, 0);
		
		cin >> N >> M;
		
		for(int i = 1; i <= N; i++){
			parent[i] = i;
		}

		for(int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;

			if(unionParent(a, b)){
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}