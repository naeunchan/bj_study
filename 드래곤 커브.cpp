#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N, ans = 0;
    int directX[4] = {1, 0, -1, 0};
    int directY[4] = {0, -1, 0, 1};
    vector<vector<bool>> board(101, vector<bool>(101, false));

    cin >> N;

    for(int i = 0; i < N; i++){
        int x, y, d, g;
        vector<int> direct;

        cin >> x >> y >> d >> g;

        board[y][x] = true;
        x += directX[d];
        y += directY[d];
        board[y][x] = true;
        direct.push_back(d);

        for(int j = 1; j <= g; j++){
            int size = direct.size() - 1;

            for(int k = size; k >= 0; k--){
                int nd = (direct[k] + 1) % 4;
                x += directX[nd];
                y += directY[nd];

                board[y][x] = true;
                direct.push_back(nd);
            }
        }
    }

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(board[i][j]){
                if(i + 1 < 101 && j + 1 < 101 && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]){
                    ans++;
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}