#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> board(13, vector<int>(13, 0));
string play[13][13];
vector<pair<pair<int, int>, int>> player;
int N, K, ans = 1;
int directX[5] = {0, 0, 0, -1, 1};
int directY[5] = {0, 1, -1, 0, 0};

int directReverse(int d){
    if(d == 1){
        return 2;
    }
    else if(d == 2){
        return 1;
    }
    else if(d == 3){
        return 4;
    }
    else{
        return 3;
    }
}

void move(string current, int nx, int ny){
    for(int i = 0; i < current.size(); i++){
        int playerNum = current[i] - '0';
        player[playerNum].first.first = nx;
        player[playerNum].first.second = ny;
    }
    play[nx][ny] += current;
}

bool blue(int x, int y, int d, string current, int i){
    d = directReverse(d);

    int nx = x + directX[d];
    int ny = y + directY[d];
    
    if(nx > 0 && nx <= N && ny > 0 && ny <= N){
        if(board[nx][ny] == 0){
            move(current, nx, ny);
        }
        else if(board[nx][ny] == 1){
            reverse(current.begin(), current.end());
            move(current, nx, ny);
        }
        else{
            play[x][y] += current;
            nx = x;
            ny = y;
        }
    }
    else{
        play[x][y] += current;
        nx = x;
        ny = y;
    }
    
    player[i].second = d;
    
    if(play[nx][ny].size() >= 4){
    	return true;
    }
    else{
    	return false;
    }
}

bool movePlayer(int x, int y, int d, string current, int nx, int ny, int i){
    if(board[nx][ny] == 0){
        move(current, nx, ny);
    }
    else if(board[nx][ny] == 1){
        reverse(current.begin(), current.end());
        move(current, nx, ny);
    }
    else{
        return blue(x, y, d, current, i);
    }

    if(play[nx][ny].size() >= 4){
    	return true;
    }
    else{
    	return false;
    }
}

int main(void){
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++){
        int x, y, d;
        cin >> x >> y >> d;
        
        player.push_back({{x, y}, d});
        play[x][y] = to_string(i);
    }
    
    while(ans <= 1000){
    	bool check = false;
    	
        for(int i = 0; i < K; i++){
            int x = player[i].first.first;
            int y = player[i].first.second;
            int d = player[i].second;
            int nx = x + directX[d];
            int ny = y + directY[d];
            int index = play[x][y].find(to_string(i));
            string current = play[x][y].substr(index);

            play[x][y] = play[x][y].substr(0, index);

            if(nx > 0 && nx <= N && ny > 0 && ny <= N){
                check = movePlayer(x, y, d, current, nx, ny, i);
            }
            else{
                check = blue(x, y, d, current, i);
            }
            
            if(check){
            	cout << ans;
            	return 0;
            }
        }
        
        ans++;
    }

    cout << -1;

    return 0;
}