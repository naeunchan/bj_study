#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans = 9999;
vector<vector<int>> board(21, vector<int>(21, 0));

void divide(int x, int y, int d1, int d2){
    vector<int> v(5, 0);

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            if(r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))){
                v[1] += board[r][c];
            }
            else if(r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))){
                v[2] += board[r][c];
            }
            else if(r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))){
                v[3] += board[r][c];
            }
            else if(r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))){
                v[4] += board[r][c];
            }
            else{
                v[0] += board[r][c];
            }
        }
    }

    sort(v.begin(), v.end());

    ans = ans < v[4] - v[0] ? ans : v[4] - v[0];
}

int main(void){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    for(int x = 1; x <= N - 2; x++){
        for(int y = 2; y <= N - 1; y++){
            for(int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++){
                for(int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++){
                    divide(x, y, d1, d2);
                }
            }
        }
    }

    cout << ans;

    return 0;
}