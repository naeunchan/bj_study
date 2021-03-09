#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> board(51, vector<int>(50, 0));
vector<vector<bool>> visited(51, vector<bool>(50, false));
int direct_x[4] = {-1, 1, 0, 0};
int direct_y[4] = {0, 0, -1, 1};
int ans = 0;
int M;
int N;

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + direct_x[i];
        int ny = y + direct_y[i];

        if(nx >= 0 && nx < M && ny >= 0 && ny < N){
            if(board[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

int main(void){
    int T;
    
    cin >> T;

    for(int t = 0; t < T; t++){
        int K;

        cin >> M >> N >> K;

        ans = 0;
        //초기화
        fill(board.begin(), board.end(), vector<int>(51, 0));
        fill(visited.begin(), visited.end(), vector<bool>(51, false));
        
        for(int i = 0; i < K; i++){
            int x, y;

            cin >> x >> y;

            board[x][y] = 1;
        }
        
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] && !visited[i][j]){
                	visited[i][j] = true;
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}