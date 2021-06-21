#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int directX[4] = {-1, 1, 0, 0};
int directY[4] = {0, 0, -1, 1};
int N = 0;
vector<vector<int>> board(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));

void check(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + directX[i];
		int ny = y + directY[i];

		if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]){
			visited[nx][ny] = true;
			check(nx, ny);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 1, max = 0;
	bool amount[101] = {false, };

	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];

			amount[board[i][j]] = true;
			max = max < board[i][j] ? board[i][j] : max;
		}
	}

	for(int r = 1; r <= max; r++){
		if(!amount[r]){
			continue;
		}
		
		vector<vector<bool>> tmp = visited;
		int cnt = 0;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] <= r){
					visited[i][j] = true;
				}
			}
		}

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!visited[i][j]){
					visited[i][j] = true;
					check(i, j);
					cnt++;
				}
			}
		}

		ans = ans < cnt ? cnt : ans;
		visited = tmp;
	}

	cout << ans;

	return 0;
}