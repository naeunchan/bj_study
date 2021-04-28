#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M, T, ans = 0, remain = 0;

    cin >> N >> M >> T;
    
    vector<deque<int>> disk;

    for(int i = 0; i < N; i++){
        deque<int> dq;

        for(int j = 0; j < M; j++){
            int n;
            
            cin >> n;
            
            dq.push_back(n);
            ans += n;
            remain++;
        }
        disk.push_back(dq);
    }

    while(T--){
        int x, d, k;
        //인접한 수의 위치를 저장하는 큐. 한꺼번에 0으로 만들어준다.
        queue<pair<int, int>> q;

        cin >> x >> d >> k;

        for(int i = x; i <= N; i += i){
            deque<int> &dq = disk[i - 1];
            int tmp = k;
            
            if(d){
                //반시계방향으로 원판 돌리기
                while(tmp--){
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
            else{
                //시계방향으로 원판 돌리기
                while(tmp--){
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
        
        //인접한 수의 위치 큐에 넣기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(disk[i][j] == 0){
                    continue;
                }

                int current = disk[i][j];
                bool isSame = false;

                if(j == 0){
                    if(current == disk[i][j + 1]){
                        q.push({i, j + 1});
                        isSame = true;
                    }

                    if(current == disk[i][M - 1]){
                        q.push({i, M - 1});
                        isSame = true;
                    }

                    if(i < N - 1 && current == disk[i + 1][j]){
                        q.push({i + 1, j});
                        isSame = true;
                    }
                }
                else if(j == M - 1){
                    if(current == disk[i][0]){
                        q.push({i, 0});
                        isSame = true;
                    }
                    
                    if(current == disk[i][j - 1]){
                        q.push({i, j - 1});
                        isSame = true;
                    }

                    if(i < N - 1 && current == disk[i + 1][j]){
                        q.push({i + 1, j});
                        isSame = true;
                    }
                }
                else{
                    if(current == disk[i][j + 1]){
                        q.push({i, j + 1});
                        isSame = true;
                    }

                    if(current == disk[i][j - 1]){
                        q.push({i, j - 1});
                        isSame = true;
                    }

                    if(i < N - 1 && current == disk[i + 1][j]){
                        q.push({i + 1, j});
                        isSame = true;
                    }
                }

                if(isSame){
                    disk[i][j] = 0;
                    ans -= current;
                    remain--;
                }
            }
        }

        if(q.empty()){
            double avg = (double)ans / (double)remain;
            ans = 0;
            remain = 0;

            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(disk[i][j] == 0){
                        continue;
                    }
                    
                    if(disk[i][j] > avg){
                        disk[i][j]--;
                    }
                    else if(disk[i][j] < avg){
                        disk[i][j]++;
                    }
                    ans += disk[i][j];
                    remain++;
                }
            }
        }
        else{
            while(!q.empty()){
                int i = q.front().first;
                int j = q.front().second;

                if(disk[i][j] != 0){
                    ans -= disk[i][j];
                    remain--;
                }
                disk[i][j] = 0;
                q.pop();
            }
        }
    }

    cout << ans;

    return 0;
}