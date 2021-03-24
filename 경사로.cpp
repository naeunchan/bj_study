#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(101, vector<int>(101, 0));
int N = 0;
int L = 0;
int ans = 0;
int directX[2] = {0, 1};
int directY[2] = {1, 0};

void dfs(int x, int y, int direction){
    int count = 1;
    bool check = true;
    int current = board[x][y];
    int t1 = x, t2 = y;

    while(x < N && y < N){
        x += directX[direction];
        y += directY[direction];

        if(current == board[x][y] || board[x][y] == 0){
            count++;
        }
        else if(current - 1 == board[x][y]){
            int tmpCount = 0;
            int nx = x;
            int ny = y;
            int lower = current - 1;

            for(int i = 0; i < L; i++){
                if(board[nx][ny] != lower){
                    check = false;
                    break;
                }

                tmpCount++;
                nx += directX[direction];
                ny += directY[direction];
            }

            if(tmpCount != L || !check){
                check = false;
                break;
            }

            if(board[nx][ny] != 0 && board[nx][ny] == board[nx - directX[direction]][ny - directY[direction]]){
                count = 1;
                x = nx;
                y = ny;
            }
            else{
                count = 0;
                x = nx - directX[direction];
                y = ny - directY[direction];
            }
            current = board[x][y];
        }
        else if(current + 1 == board[x][y]){
            if(count < L){
                check = false;
                break;
            }
            current += 1;
            count = 1;
        }
        else{
            check = false;
            break;
        }

        if(!check){
            break;
        }
    }

    if(check){
        ans++;
        cout << t1 << " " << t2 << " " << direction << endl;
    }
}

int main(void){
    cin >> N >> L;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        if(i == 0){
            for(int j = 0; j < N; j++){
                dfs(i, j, 1);
            }
        }
        dfs(i, 0, 0);
    }

    cout << ans;

    return 0;
}