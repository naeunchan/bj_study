#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;

    cin >> N;

    vector<int> stairs(N + 1, 0);
    vector<int> dp(N + 1, 0);

    for(int i = 1; i <= N; i++){
        cin >> stairs[i];
    }
    
    //1번째 계단을 밟을 때 dp[1] = stairs[1]
    //1번째 계단을 밟고 2번째 계단을 밟을 때 dp[2] = staris[1] + stairs[2]
    //1번째 + 3번째 계단과 2번째 + 3번째 계단을 밟을 때 더 큰 경우를 dp[3]에 저장
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = stairs[2] > stairs[1] ? stairs[2] + stairs[3] : stairs[1] + stairs[3];

    //dp[i] = (i - 3번 계단까지 누적 값 + i - 1번째 계단의 값) > (i - 2번 계단까지 누적 값) ? dp[i - 3] + stairs[i - 1] + stairs[i] : dp[i - 2] + stairs[i]
    for(int i = 4; i <= N; i++){
        dp[i] = dp[i - 3] + stairs[i - 1] > dp[i - 2] ? dp[i - 3] + stairs[i - 1] + stairs[i] : dp[i - 2] + stairs[i];
    }

    cout << dp[N];

    return 0;
}