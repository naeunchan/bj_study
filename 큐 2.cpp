#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        int num;

        cin >> s;

        if(s == "push"){
            cin >> num;
            q.push(num);
        }
        else if(s == "pop"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s == "size"){
            cout << q.size() << "\n";
        }
        else if(s == "empty"){
            if(q.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(s == "front"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        else if(s == "back"){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}