#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int reverse(int direct){
    switch(direct){
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
    }
}

int main(void){
    int R, C, M, ans = 0;
    int directX[4] = {-1, 1, 0, 0};
    int directY[4] = {0, 0, 1, -1};
    queue<pair<int, pair<int, pair<int, pair<int, int>>>>> q;

    cin >> R >> C >> M;

    vector<pair<int, pair<int, int>>> board[101][101];

    for(int i = 0; i < M; i++){
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        if(d == 1 || d == 2){
            s %= ((R - 1) * 2);
        }
        else{
            s %= ((C - 1) * 2);
        }
        board[r - 1][c - 1].push_back({s, {d, z}});
    }

    for(int i = 0; i < C; i++){
        //낚시 시작
        bool check = false;

        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(c == i && !check && !board[r][c].empty()){
                    ans += board[r][c].back().second.second;
                    board[r][c].pop_back();
                    check = true;
                }
                else if(!board[r][c].empty()){
                    q.push({r, {c, {board[r][c].back().first, {board[r][c].back().second.first, board[r][c].back().second.second}}}});
                    board[r][c].pop_back();
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second.first;
            int s = q.front().second.second.first;
            int d = q.front().second.second.second.first;
            int z = q.front().second.second.second.second;
            q.pop();
            
            for(int j = 0; j < s; j++){
                x += directX[d - 1];
                y += directY[d - 1];

                if(x < 0){
                    d = reverse(d);
                    x = 1;
                }
                else if(x == R){
                    d = reverse(d);
                    x = R - 2;
                }

                if(y < 0){
                    d = reverse(d);
                    y = 1;
                }
                else if(y == C){
                    d = reverse(d);
                    y = C - 2;
                }
            }

            if(!board[x][y].empty()){
                if(board[x][y].back().second.second < z){
                    board[x][y].pop_back();
                    board[x][y].push_back({s, {d, z}});       
                }
            }
            else{
                board[x][y].push_back({s, {d, z}});
            }
        }
    }

    cout << ans;

    return 0;
}