#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int N, M, r, c, d, ans = 0;
    //0 = 북, 1 = 동, 2 = 남, 3 = 서
    int directX[4] = {-1, 0, 1, 0};
    int directY[4] = {0, 1, 0, -1};
    queue<pair<pair<int, int>, int>> q;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    cin >> r >> c >> d;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    q.push({{r, c}, d});

    while(!q.empty()){
        //check 변수는 4방향 중 청소 할 공간 여부를 나타낸다.
        int x = q.front().first.first;
        int y = q.front().first.second;
        int direct = q.front().second;
        bool check = false;

        q.pop();
        
        if(!visited[x][y]){
            ans++;
            visited[x][y] = true;
        }

        for(int i = 0; i < 4; i++){
            //현재 방향에서 왼쪽 방향부터 탐색
            int nd = (4 + direct - (1 + i)) % 4;
            int nx = x + directX[nd];
            int ny = y + directY[nd];

            //회전한 방향에 청소할 공간이 있으면 큐에 삽입 후 break.
            if(!board[nx][ny] && !visited[nx][ny]){
                q.push({{nx, ny}, direct});
                check = true;
                break;
            }
        }

        //check == false인 경우 4 방향 모두 청소를 했고 후진이 필요하다.
        //후진했을 때 청소 여부 상관 없이 빈칸이면 큐에 삽입.
        if(!check){
            int nd = (direct + 2) % 4;
            int nx = x + directX[nd];
            int ny = y + directY[nd];

            if(!board[nx][ny]){
                q.push({{nx, ny}, direct});
            }
        }
    }

    cout << ans;

    return 0;
}