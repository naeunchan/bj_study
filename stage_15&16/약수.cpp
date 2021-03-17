#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, ans;
    vector<int> v;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    ans = v.front() * v.back();

    cout << ans;

    return 0;
}