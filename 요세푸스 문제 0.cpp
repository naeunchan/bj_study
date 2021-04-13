#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int n, k, count = 0;
    queue<int> q;
    vector<int> v;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(!q.empty()){
        if(++count == k){
            count = 0;
            v.push_back(q.front());
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }

    cout << "<";
    for(int i = 0; i < n; i++){
        if(i < n - 1){
            cout << v[i] << ", ";
        }
        else{
            cout << v[i] << ">";
        }
    }

    return 0;
}