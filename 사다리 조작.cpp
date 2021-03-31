#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int M;
int H;
int ans = INT_MAX;
vector<vector<bool>> ladder(11, vector<bool>(30, false));

bool check(){
    for(int i = 1; i <= N; i++){
        int start = i;

        for(int j = 1; j <= H; j++){
            if(ladder[start][j]){
                start++;
            }
            else if(ladder[start - 1][j]){
                start--;
            }
        }

        if(start != i){
            return false;
        }
    }
    return true;
}

void dfs(int start, int count){
    if(count >= 4){
        return;
    }
	
	if(check()){
        ans = ans < count ? ans : count;
        return;
    }
    
    for(int i = start; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(ladder[j][i] || ladder[j - 1][i] || ladder[j + 1][i]){
                continue;
            }

            ladder[j][i] = true;
            dfs(i, count + 1);
            ladder[j][i] = false;
        }
    }
}

int main(void){
    cin >> N >> M >> H;


    for(int i = 0; i < M; i++){
        int a, b;

        cin >> a >> b;
        
        ladder[b][a] = true;
    }
	
    dfs(1, 0);

    if(ans == INT_MAX){
        ans = -1;
    }

    cout << ans;

    return 0;
}