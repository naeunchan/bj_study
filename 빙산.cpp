#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N = 0;
int M = 0;
int directX[4] = {-1, 1, 0, 0};
int directY[4] = {0, 0, -1, 1};

void check(vector<vector<int>> board, int x, int y, vector<vector<bool>> &visited){
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;

	while(!q.empty()){
		for(int i = 0; i < 4; i++){
			int nx = q.front().first + directX[i];
			int ny = q.front().second + directY[i];
			
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] && !visited[nx][ny]){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
		q.pop();
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	queue<pair<int, int>> q;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];

			if(board[i][j]){
				q.push(make_pair(i, j));
			}
		}
	}

	while(!q.empty()){
		int size = q.size();
		int cnt = 0;
		vector<vector<int>> tmpBoard(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		//빙산 분리 확인
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(board[i][j] && !visited[i][j]){
					check(board, i, j, visited);
					cnt++;
				}
			}
		}

		if(cnt >= 2){
			cout << ans;
			return 0;
		}

		//빙산이 녹음
		while(size--){
			int x = q.front().first;
			int y = q.front().second;
			int water = 0;

			q.pop();

			for(int i = 0; i < 4; i++){
				int nx = x + directX[i];
				int ny = y + directY[i];

				if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == 0){
					water++;
				}
			}
			tmpBoard[x][y] = board[x][y] - water <= 0 ? 0 : board[x][y] - water;

			if(tmpBoard[x][y]){
				q.push(make_pair(x, y));
			}
		}
		
		ans++;
		board = tmpBoard;
	}
	
	cout << 0;

	return 0;
}