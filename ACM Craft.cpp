#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    while(T--){
        int N, K, W, ans = 0;
        queue<int> q;
        
        cin >> N >> K;

        vector<int> topology(N + 1, 0);
        vector<vector<int>> graph(N + 1);
        vector<int> time(N + 1, 0);
        vector<int> dp(N + 1, 0);

        for(int i = 1; i <= N; i++){
            cin >> time[i];
        }

        while(K--){
            int X, Y;

            cin >> X >> Y;
            topology[Y]++;
            graph[X].push_back(Y);
        }

        cin >> W;

        for(int i = 1; i <= N; i++){
            if(topology[i] == 0){
                dp[i] += time[i];
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            
            q.pop();

            for(int j = 0; j < graph[front].size(); j++){
                int next = graph[front][j];

                dp[next] = dp[next] < dp[front] + time[next] ? dp[front] + time[next] : dp[next];

                if(--topology[next] == 0){
                    q.push(next);
                }
            }
        }

        cout << dp[W] << endl;
    }

    return 0;
}