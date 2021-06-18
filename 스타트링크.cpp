#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int F, S, G, U, D;
	int ans = 0;
	queue<int> q;
	vector<bool> visited(1000001, false);

	cin >> F >> S >> G >> U >> D;

	q.push(S);
	visited[S] = true;

	while(!q.empty()){
		int size = q.size();

		while(size--){
			int current = q.front();
			
			q.pop();

			if(current == G){
				cout << ans;
				return 0;
			}

			int us = current + U;
			int ds = current - D;

			if(us >= 1 && us <= F && !visited[us]){
				q.push(us);
				visited[us] = true;
			}

			if(ds >= 1 && ds <= F && !visited[ds]){
				q.push(ds);
				visited[ds] = true;
			}
		}
		
		ans++;
	}

	cout << "use the stairs";

	return 0;
}