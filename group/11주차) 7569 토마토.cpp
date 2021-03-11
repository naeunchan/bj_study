#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int box[100][100][100];
bool visited[100][100][100];

int main(void){
    int M, N, H;
    int direct_x[6] = {0, 0, 0, 0, -1, 1};
    int direct_y[6] = {0, 0, -1, 1, 0, 0};
    int direct_z[6] = {-1, 1, 0, 0, 0, 0};
    int tomato = 0, ans = 0;

    queue<pair<int, pair<int, int>>> q;

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> box[i][j][k];

                if(box[i][j][k] == 0){
                    //안 익은 토마토의 개수 구하기
                    tomato++;
                }
                else if(box[i][j][k] == 1){
                    //익은 토마토 큐에 넣기
                    q.push({i, {j, k}});
                    visited[i][j][k] = true;
                }
            }
        }
    }

    //안익은 토마토가 없을 때 0 리턴
    if(tomato == 0){
        cout << 0;
        return 0;
    }

    //BFS
    while(!q.empty()){
        int size = q.size();
		
        for(int i = 0; i < size; i++){
            int z = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            q.pop();
            
            for(int j = 0; j < 6; j++){
                int nz = z + direct_z[j];
                int nx = x + direct_x[j];
                int ny = y + direct_y[j];

                if(nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(box[nz][nx][ny] == 0 && !visited[nz][nx][ny]){
                        visited[nz][nx][ny] = true;
                        q.push({nz, {nx, ny}});
                        tomato--;
                    }
                }
            }
        }
        ans++;
    }
    
    //안 익은 토마토가 남아있으면 -1 출력
    if(tomato > 0){
        cout << -1;
    }
    else{
        cout << ans - 1;
    }

    return 0;
}