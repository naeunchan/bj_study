#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p1, p2, m, ans = 1;
	queue<int> q;
	vector<vector<bool>> graph(101, vector<bool>(101, false));
	vector<bool> check(101, false);

	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	for(int i = 0; i < m; i++){
		int x, y;

		cin >> x >> y;
		graph[x][y] = true;
		graph[y][x] = true;
	}

	q.push(p1);
	check[p1] = true;

	while(!q.empty()){
		int size = q.size();

		while(size--){
			int current = q.front();

			q.pop();

			for(int i = 1; i <= n; i++){
				if(graph[current][i] && !check[i]){
					if(i == p2){
						cout << ans;
						return 0;
					}

					q.push(i);
					check[i] = true;
				}
			}
		}
		ans++;
	}
	
	cout << -1;
	
	return 0;
}