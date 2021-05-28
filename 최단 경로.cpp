#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, start;
	vector<pair<int, int>> graph[200001];
	priority_queue<pair<int, int>> pq;
	vector<int> dist(200001, INF);

	cin >> V >> E;
	cin >> start;

	for(int i = 0; i < E; i++){
		int u, v, w;

		cin >> u >> v >> w;

		graph[u].push_back(make_pair(v, w));
	}

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

	for(int i = 1; i <= V; i++){
		if(dist[i] == INF){
			cout << "INF" << endl;
		}
		else{
			cout << dist[i] << endl;
		}
	}

	return 0;
}