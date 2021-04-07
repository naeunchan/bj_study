#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    //ap[0] = 공기청정기 윗 부분, ap[1] = 공기청정기 아래 부분
    int R, C, T, ans = 0;
    vector<pair<int, int>> ap;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, -1, 1};

    cin >> R >> C >> T;

    vector<vector<int>> board(R, vector<int>(C, 0));
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
            
            if(board[i][j] > 0){
                q.push({{i, j}, board[i][j]});
            }
            else if(board[i][j] == -1){
                ap.push_back({i, j});
            }
        }
    }
    
    while(T--){
        queue<pair<pair<int, int>, int>> tmpQ;
        int upAir = 0, downAir = 0;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dust = q.front().second;
            int count = 0;

            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + directX[j];
                int ny = y + directY[j];
                
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && board[nx][ny] > -1){
                    tmpQ.push({{nx, ny}, dust / 5});
                    count++;
                }
            }
            board[x][y] = dust - ((dust / 5) * count);
        }

        while(!tmpQ.empty()){
            int x = tmpQ.front().first.first;
            int y = tmpQ.front().first.second;
            int dust = tmpQ.front().second;

            tmpQ.pop();
            board[x][y] += dust;
        }
        
        //공기청정기 위쪽, 아래쪽 바람
        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    for(int j = ap[0].second + 1; j < C; j++){
                        swap(upAir, board[ap[0].first][j]);
                    }
                    for(int j = ap[1].second + 1; j < C; j++){
                        swap(downAir, board[ap[1].first][j]);
                    }
                    break;

                case 1:
                    for(int j = ap[0].first - 1; j >= 0; j--){
                        swap(upAir, board[j][C - 1]);
                    }
                    for(int j = ap[1].first + 1; j < R; j++){
                        swap(downAir, board[j][C - 1]);
                    }
                    break;

                case 2:
                    for(int j = C - 2; j >= 0; j--){
                        swap(upAir, board[0][j]);
                    }
                    for(int j = C - 2; j >= 0; j--){
                        swap(downAir, board[R - 1][j]);
                    }
                    break;

                case 3:
                    for(int j = 1; j < ap[0].first; j++){
                        swap(upAir, board[j][0]);
                    }
                    for(int j = R - 2; j > ap[1].first; j--){
                        swap(downAir, board[j][0]);
                    }
                    break;
            }
        }
        
        //현재 남아있는 미세먼지 큐에 넣기
        for(int i = 0; i < R; i++){
        	for(int j = 0; j < C; j++){
        		if(board[i][j] > 0){
        			q.push({{i, j}, board[i][j]});
        		}
        	}
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] > 0){
                ans += board[i][j];
            }
        }
    }

    cout << ans;
    return 0;
}