#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, X, answer = 0;
    int start = 0, end = 0;

    cin >> n;

    vector<int> v(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    end = v.size() - 1;

    cin >> X;

    while(start < end){
        int sum = v[start] + v[end];

        if(sum == X){
            answer++;
            start++;
        }
        else if(sum < X){
            start++;
        }
        else{
            end--;
        }
    }

    cout << answer;
    
    return 0;
}