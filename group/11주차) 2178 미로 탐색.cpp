#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int N, M, ans = 1;
    int direct_x[4] = {-1, 1, 0, 0};
    int direct_y[4] = {0, 0, -1, 0};
    int goalX = 0, goalY = 0;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    goalX = N - 1;
    goalY = M - 1;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;

        for(int j = 0; j < M; j++){
            board[i][j] = s[j] - '0';
        }
    }
        
    q.push({0, 0});
    
    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + direct_x[j];
                int ny = y + direct_y[j];

                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(board[nx][ny] && !visited[nx][ny]){
                        if(nx == goalX && ny == goalY){
                            cout << ans + 1;
                            return 0;
                        }
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        ans++;
    }
    
    return 0;
}