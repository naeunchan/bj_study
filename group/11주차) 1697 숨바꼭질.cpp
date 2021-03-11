#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int N, K, ans = 0;
    int direct_x[3] = {-1, 1, 2};
    vector<int> board(200001, 0);
    vector<bool> visited(200001, false);
    queue<int> q;

    cin >> N >> K;

    //같은 점에 위치할 때
    if(N == K){
        cout << 0;
        return 0;
    }
    
    board[N] = 1;
    visited[N] = true;

    q.push(N);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            int x = q.front();
            
            q.pop();
            
            for(int j = 0; j < 3; j++){
                int nx = 0;

                //-1, 1, * 2 처리
                if(j != 2){
                    nx = x + direct_x[j];
                }
                else{
                    nx = x * direct_x[j];
                }

                if(nx >= 0 && nx < 100001 & !visited[nx]){
                    if(nx == K){
                        cout << ++ans;
                        return 0;
                    }

                    visited[nx] = true;
                    q.push(nx);
                }
            }
        }
        ans++;
    }

    return 0;
}