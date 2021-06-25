#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<vector<bool>> graph(10001, vector<bool>(10001, 0));
vector<bool> visited(10001, false);

void dfs(int start){
	visited[start] = true;

	for(int i = 1; i <= N; i++){
		if(!visited[i] && graph[start][i]){
			dfs(i);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	cin >> N >> M;

	for(int i = 0; i < M; i++){
		int u, v;

		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}