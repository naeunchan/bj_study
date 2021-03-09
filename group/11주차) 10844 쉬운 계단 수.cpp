#include <iostream>
#include <vector>
#define MOD 1000000000

using namespace std;

int main(void){
    int N;
    long long ans = 0;
    vector<vector<long long>> dp(101, vector<long long>(11, 0));

    cin >> N;

    //1 자리수
    for(int i = 1; i < 10; i++){
        dp[1][i] = 1;
    }

    //2 자리수 ~ N 자리수
    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i - 1][1] % MOD;

        //메모이제이션
        for(int j = 1; j < 10; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for(int i = 0; i < 10; i++){
        ans += dp[N][i];
    }

    cout << ans % MOD;

    return 0;
}