#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int K;
    long long ans = 0;
    stack<int> stk;

    cin >> K;

    for(int i = 0; i < K; i++){
        int num;

        cin >> num;

        if(num == 0){
            stk.pop();
        }
        else{
            stk.push(num);
        }
    }

    while(!stk.empty()){
    	ans += stk.top();
    	stk.pop();
    }

    cout << ans;
    
    return 0;
}