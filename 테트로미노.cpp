#include <iostream>
#include <vector>
 
using namespace std;

bool check(int num, int limit){
    return num >= 0 && num < limit;
}

int main(void){
    int N, M, ans = 0;
    int shapeX[28][4] = {{0,0,0,0}, {0,1,2,3}, {0,-1,-2,-3}, {0,0,0,0}, {0,0,-1,-2}, {0,1,1,1}, {0,0,1,2}, {0,-1,-1,-1}, {0,0,-1,-2}, {0,1,1,1}, {0,0,1,2}, {0,-1,-1,-1}, {0,0,1,1}, {0,0,-1,-1}, {0,-1,-1,0}, {0,0,1,1}, {0,1,1,2}, {0,0,-1,-1}, {0,-1,-1,-2}, {0,0,1,1}, {0,1,1,2}, {0,0,-1,-1}, {0,-1,-1,-2}, {0,0,1,1}, {0,1,1,1}, {0,0,-1,1}, {0,-1,-1,-1}, {0,0,-1,1}};
    int shapeY[28][4] = {{0,1,2,3}, {0,0,0,0}, {0,0,0,0}, {0,-1,-2,-3}, {0,-1,-1,-1}, {0,0,-1,-2}, {0,1,1,1}, {0,0,1,2}, {0,1,1,1}, {0,0,1,2}, {0,-1,-1,-1}, {0,0,-1,-2}, {0,1,0,1}, {0,1,1,0}, {0,0,-1,-1}, {0,-1,-1,0},{0,0,1,1}, {0,1,1,2}, {0,0,-1,-1}, {0,-1,-1,-2}, {0,0,-1,-1}, {0,-1,-1,-2}, {0,0,1,1}, {0,1,1,2}, {0,0,-1,1}, {0,1,1,1}, {0,0,-1,1}, {0,-1,-1,-1}};
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 28; k++){
                int x1 = i + shapeX[k][0];
                int x2 = i + shapeX[k][1];
                int x3 = i + shapeX[k][2];
                int x4 = i + shapeX[k][3];
                int y1 = j + shapeY[k][0];
                int y2 = j + shapeY[k][1];
                int y3 = j + shapeY[k][2];
                int y4 = j + shapeY[k][3];

                if(check(x1, N) && check(x2, N) && check(x3, N) && check(x4, N) && check(y1, M) && check(y2, M) && check(y3, M) && check(y4, M)){
                    int sum = board[x1][y1] + board[x2][y2] + board[x3][y3] + board[x4][y4];
                    ans = ans < sum ? sum : ans;
                }
            }
        }
    }

    cout << ans;

    return 0;
}