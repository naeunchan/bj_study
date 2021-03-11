#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int main(void){
    //3차원 배열을 이용해 벽을 부숴서 이동했을 때와 벽을 부수지 않고 이동했을 때를 나눈다.
    int N, M, ans = 1;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, -1, 1};
    int board[2][1001][1001] = {0, };
    int visited[2][1001][1001] = {false, };
    queue<pair<pair<int, int>, int>> q;

    cin >> N >> M;

    int goalX = N - 1;
    int goalY = M - 1;

    //맵 정보
    for(int i = 0; i < N; i++){
        string s;
		
		cin >> s;
		
        for(int j = 0; j < M; j++){
            board[0][i][j] = s[j] - '0';
            board[1][i][j] = s[j] - '0';
        }
    }
    
    q.push({{0, 0}, 0});
    visited[0][0][0] = true;
    visited[1][0][0] = true;

    while(!q.empty()){
        //벽을 부수지 않고 이동하는 경우 board[0][x][y]를 탐색하고,
        //벽을 부순 경우 board[1][x][y]를 탐색
        int size = q.size();

        for(int i = 0; i < size; i++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int destroyed = q.front().second;

            q.pop();
            
            if(x == goalX && y == goalY){
                cout << ans;
                return 0;
            }

            for(int j = 0; j < 4; j++){
                int nx = x + directX[j];
                int ny = y + directY[j];

                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(board[destroyed][nx][ny] == 0 && !visited[destroyed][nx][ny]){
                        visited[destroyed][nx][ny] = true;
                        q.push({{nx, ny}, destroyed});
                    }

                    if(board[destroyed][nx][ny] == 1 && !visited[destroyed][nx][ny] && destroyed == 0){
                        visited[destroyed][nx][ny] = true;
                        q.push({{nx, ny}, 1});
                    }
                }
            }
        }

        ans++;
    }

    cout << -1;

    return 0;
}