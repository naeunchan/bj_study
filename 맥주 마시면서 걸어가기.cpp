#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		int n;
		int sx, sy;
		int tx, ty;
		bool check = false;
		queue<pair<int, int>> q;
		vector<pair<int, int>> target;

		cin >> n;
		cin >> sx >> sy;

		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;

			target.push_back(make_pair(x, y));
		}

		cin >> tx >> ty;

		target.push_back(make_pair(tx, ty));

		q.push(make_pair(sx, sy));

		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			if(x == tx && y == ty){
				cout << "happy" << endl;
				check = true;
				break;
			}

			for(auto itr = target.begin(); itr != target.end(); itr++){
				int nx = abs(x - itr->first);
				int ny = abs(y - itr->second);

				if(nx + ny <= 1000){
					q.push(make_pair(itr->first, itr->second));
					target.erase(itr);
					itr--;
				}
			}
		}
		
		if(!check){
			cout << "sad" << endl;
		}
	}

	return 0;
}