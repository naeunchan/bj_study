#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
int ans = 0;
vector<pair<int, int>> v;

vector<vector<int>> upCheck(int x, int y, vector<vector<int>> board){
    for(int i = x - 1; i >= 0; i--){
        if(board[i][y] == 6){
            return board;
        }
        else if(board[i][y] == 0){
            board[i][y] = -1;
        }
    }
    return board;
}

vector<vector<int>> downCheck(int x, int y, vector<vector<int>> board){
    for(int i = x + 1; i < N; i++){
        if(board[i][y] == 6){
            return board;
        }
        else if(board[i][y] == 0){
            board[i][y] = -1;
        }
    }
    return board;
}

vector<vector<int>> leftCheck(int x, int y, vector<vector<int>> board){
    for(int i = y - 1; i >= 0; i--){
        if(board[x][i] == 6){
            return board;
        }
        else if(board[x][i] == 0){
            board[x][i] = -1;
        }
    }
    return board;
}

vector<vector<int>> rightCheck(int x, int y, vector<vector<int>> board){
    for(int i = y + 1; i < M; i++){
        if(board[x][i] == 6){
            return board;
        }
        else if(board[x][i] == 0){
            board[x][i] = -1;
        }
    }
    return board;
}

void cameraCheck(vector<vector<int>> board){
    int sum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 0){
                sum++;
            }
        }
    }

    ans = ans > sum ? sum : ans;
}

void dfs(int index, vector<vector<int>> board){
    if(index == v.size()){
        cameraCheck(board);
        return;
    }

    int x = v[index].first;
    int y = v[index].second;
    vector<vector<int>> tmpBoard;   

    switch(board[x][y]){
        case 1:
            tmpBoard = upCheck(x, y, board);
            dfs(index + 1, tmpBoard);

            tmpBoard = downCheck(x, y, board);
            dfs(index + 1, tmpBoard);

            tmpBoard = leftCheck(x, y, board);
            dfs(index + 1, tmpBoard);

            tmpBoard = rightCheck(x, y, board);
            dfs(index + 1, tmpBoard);
            break;

        case 2:
            tmpBoard = rightCheck(x, y, board);
            tmpBoard = leftCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = upCheck(x, y, board);
            tmpBoard = downCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);
            break;

        case 3:
            tmpBoard = upCheck(x, y, board);
            tmpBoard = rightCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = rightCheck(x, y, board);
            tmpBoard = downCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = downCheck(x, y, board);
            tmpBoard = leftCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = leftCheck(x, y, board);
            tmpBoard = upCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);
            break;

        case 4:
            tmpBoard = leftCheck(x, y, board);
            tmpBoard = upCheck(x, y, tmpBoard);
            tmpBoard = rightCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = upCheck(x, y, board);
            tmpBoard = rightCheck(x, y, tmpBoard);
            tmpBoard = downCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = rightCheck(x, y, board);
            tmpBoard = downCheck(x, y, tmpBoard);
            tmpBoard = leftCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);

            tmpBoard = downCheck(x, y, board);
            tmpBoard = leftCheck(x, y, tmpBoard);
            tmpBoard = upCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);
            break;

        case 5:
            tmpBoard = upCheck(x, y, board);
            tmpBoard = downCheck(x, y, tmpBoard);
            tmpBoard = leftCheck(x, y, tmpBoard);
            tmpBoard = rightCheck(x, y, tmpBoard);
            dfs(index + 1, tmpBoard);
            break;
    }
}

int main(void){
    vector<vector<int>> board(8, vector<int>(8, 0));

    cin >> N >> M;

    ans = N * M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];

            //cctv 위치 v 벡터에 삽입
            if(board[i][j] >= 1 && board[i][j] <= 5){
                v.push_back({i, j});
            }
        }
    }

	if(!v.empty()){
    	dfs(0, board);
	}
    else{
        cameraCheck(board);
    }

    cout << ans;

    return 0;
}   