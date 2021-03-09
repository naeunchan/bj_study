#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000001, -1);
//vector<int> dp(100001, 0);

int make(int N){
    if(N == 1){
       return 0;
    }

    if(dp[N] != -1){
        return dp[N];
    }

    int result = make(N - 1) + 1;

    if(N % 3 == 0){
        result = min(result, make(N / 3) + 1);
    }
    if(N % 2 == 0){
        result = min(result, make(N / 2) + 1);
    }
    dp[N] = result;

    return dp[N];
}

int main(void){
    int N;

    cin >> N;

    cout << make(N);

    // for(int i = 2; i <= N; i++){
    //     dp[i] = dp[i - 1] + 1;
    //     if(i % 2 == 0){
    //         dp[i] = min(dp[i / 2] + 1, dp[i]);
    //     }
    //     if(i % 3 == 0){
    //         dp[i] = min(dp[i / 3] + 1, dp[i]);
    //     }
    // }
    return 0;
}