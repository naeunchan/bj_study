#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

int dijkstra(int start, int end, vector<pair<int, int>> *graph){
	priority_queue<pair<int, int>> pq;
	vector<int> dist(2001, INF);
	
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

	int T;

	cin >> T;

	while(T--){
		int n, m, t, s, g, h;
		long long ans1 = 0, ans2 = 0;
		priority_queue<pair<int, int>> pq;
		vector<pair<int, int>> graph[2001];
		vector<int> destination;
		vector<int> answer;

		cin >> n >> m >> t;
		cin >> s >> g >> h;

		while(m--){
			int a, b, d;

			cin >> a >> b >> d;

			graph[a].push_back(make_pair(b, d));
			graph[b].push_back(make_pair(a, d));
		}

		while(t--){
			int x;

			cin >> x;

			destination.push_back(x);
		}

		ans1 += dijkstra(s, g, graph);
		ans1 += dijkstra(g, h, graph);

		ans2 += dijkstra(s, h, graph);
		ans2 += dijkstra(h, g, graph);
		
		for(int i = 0; i < destination.size(); i++){
			long long tmp1, tmp2;

			tmp1 = ans1 + dijkstra(h, destination[i], graph);
			tmp2 = ans2 + dijkstra(g, destination[i], graph);
			
			if(tmp1 < INF || tmp2 < INF){
				if(tmp1 < tmp2 && tmp1 <= dijkstra(s, destination[i], graph)){
					answer.push_back(destination[i]);
				}
				else if(tmp2 < tmp1 && tmp2 <= dijkstra(s, destination[i], graph)){
					answer.push_back(destination[i]);
				}
			}
		}

		sort(answer.begin(), answer.end());

		for(int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}

		cout << endl;
	}

	return 0;
}