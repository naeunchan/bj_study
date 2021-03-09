//계단 오르기 문제와 비슷
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    
    cin >> N;

    vector<int> wine(N + 1, 0);
    vector<int> dp(N + 1, 0);

    for(int i = 1; i <= N; i++){
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = wine[2] > wine[1] ? wine[2] + wine[3] : wine[1] + wine[3];

    for(int i = 4; i <= N; i++){
        dp[i] = wine[i] + max(dp[i - 3] + wine[i - 1], dp[i - 2], dp[i - 4] + wine[i - 1]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}