#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    int N, M, answer = 9999, totalVirus = 0;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, -1, 1};
    bool check = false;
    int space = 0;

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<pair<int, int>> virus;
    vector<int> ind(M, 1);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];

            if(board[i][j] == 2){
                virus.push_back({i, j});
                totalVirus++;
            }
            else if(board[i][j] == 0){
                space++;
            }
        }
    }

    for(int i = M; i < totalVirus; i++){
        ind.push_back(0);
    }

    sort(ind.begin(), ind.end());

    do{
        int time = 0;
        int tmpSpace = space;
        queue<pair<int, int>> activeVirus;
        vector<vector<int>> tmpBoard = board;
        vector<vector<bool>> tmpVisited(N, vector<bool>(N, false));

        for(int i = 0; i < ind.size(); i++){
            if(ind[i]){
                //활성 바이러스
                activeVirus.push(virus[i]);
                tmpVisited[virus[i].first][virus[i].second] = true;
            }
        }

        while(!activeVirus.empty()){
        	if(!tmpSpace){
        		break;
        	}
        	
            int size = activeVirus.size();

            for(int i = 0; i < size; i++){
                int x = activeVirus.front().first;
                int y = activeVirus.front().second;

                activeVirus.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + directX[j];
                    int ny = y + directY[j];

                    if(nx >= 0 && nx < N && ny >= 0 && ny < N  && !tmpVisited[nx][ny]){
                        if(tmpBoard[nx][ny] == 0){
                            activeVirus.push({nx, ny});
                            tmpVisited[nx][ny] = true;
                            tmpSpace--;
                        }
                        else if(tmpBoard[nx][ny] == 2 && tmpSpace > 0){
                            activeVirus.push({nx, ny});
                            tmpVisited[nx][ny] = true;
                        }
                    }
                }
            }

            time++;
        }
        
        if(!tmpSpace){
            answer = answer < time ? answer : time;
            check = true;
        }
    }while(next_permutation(ind.begin(), ind.end()));

    if(!check){
        cout << -1;
    }
    else{
        cout << answer;
    }

    return 0;
}