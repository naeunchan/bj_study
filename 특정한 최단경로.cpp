#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[200001];

int dijkstra(int start, int end){
	priority_queue<pair<int, int>> pq;
	vector<int> dist(200001, INF);
	
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while(!pq.empty()){
		int cost = -pq.top().first;
		int current = pq.top().second;

		pq.pop();

		if(dist[current] < cost){
			continue;
		}

		for(int i = 0; i < graph[current].size(); i++){
			int next = graph[current][i].first;
			int nextCost = graph[current][i].second + cost;

			if(dist[next] > nextCost){
				dist[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
	return dist[end];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E, v1, v2;
    long long ans1 = 0, ans2 = 0;
	priority_queue<pair<int, int>> pq;

	cin >> N >> E;

	for(int i = 0; i < E; i++){
		int a, b, c;

		cin >> a >> b >> c;

		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	cin >> v1 >> v2;
	
	ans1 += dijkstra(1, v1);
	ans1 += dijkstra(v1, v2);
	ans1 += dijkstra(v2, N);

	ans2 += dijkstra(1, v2);
	ans2 += dijkstra(v2, v1);
	ans2 += dijkstra(v1, N);

	if(ans1 >= INF && ans2 >= INF){
		cout << -1;
	}
	else{
		cout << min(ans1, ans2);
	}

	return 0;
}