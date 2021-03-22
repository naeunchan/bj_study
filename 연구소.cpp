#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int N, M, answer = 0;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, -1, 1};
    vector<pair<int, int>> wall;
    queue<pair<int, int>> q;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
     
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            
            if(board[i][j] == 0){
                wall.push_back({i, j});
            }
            else if(board[i][j] == 2){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    vector<int> index(wall.size(), 0);

    index[wall.size() - 1] = index[wall.size() - 2] = index[wall.size() - 3] = 1;

    do{
        int sum = 0;
        vector<vector<int>> tmpBoard = board;
        vector<vector<bool>> tmpVisited = visited;
        queue<pair<int, int>> tmpQ = q;
        
        for(int i = 0; i < index.size(); i++){
            if(index[i]){
                tmpBoard[wall[i].first][wall[i].second] = 1;
            }
        }

        while(!tmpQ.empty()){
            int size = tmpQ.size();

            for(int i = 0; i < size; i++){
                int x = tmpQ.front().first;
                int y = tmpQ.front().second;

                tmpQ.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + directX[j];
                    int ny = y + directY[j];

                    if(nx >= 0 && nx < N && ny >= 0 && ny < M && tmpBoard[nx][ny] == 0 && !tmpVisited[nx][ny]){
                        tmpQ.push({nx, ny});
                        tmpVisited[nx][ny] = true;
                        tmpBoard[nx][ny] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tmpBoard[i][j] == 0){
                    sum++;
                }
            }
        }

        answer = answer < sum ? sum : answer;
    }while(next_permutation(index.begin(), index.end()));
    
    cout << answer;

    return 0;
}