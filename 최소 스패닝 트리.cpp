#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> parent(10001, 0);

bool compare(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

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

	int V, E, ans = 0;
	
	cin >> V >> E;

	for(int i = 1; i <= V; i++){
		parent[i] = i;
	}

	for(int i = 0; i < E; i++){
		vector<int> v;
		int a, b, c;

		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		graph.push_back(v);
	}

	sort(graph.begin(), graph.end(), compare);

	for(int i = 0; i < graph.size(); i++){
		if(unionParent(graph[i][0], graph[i][1])){
			ans += graph[i][2];
		}
	}

	cout << ans;
	
	return 0;
}