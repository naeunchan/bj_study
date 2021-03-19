#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int N;
    stack<int> stk;

    cin >> N;

    for(int i = 0; i < N; i++){
        string cmd;
        int n;

        cin >> cmd;

        if(cmd == "push"){
            cin >> n;
            stk.push(n);
        }
        else if(cmd == "pop"){
            if(stk.empty()){
                cout << -1 << endl;
            }
            else{
                n = stk.top();
                stk.pop();
                cout << n << endl;
            }
        }
        else if(cmd == "size"){
            cout << stk.size() << endl;
        }
        else if(cmd == "empty"){
            if(stk.empty()){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(cmd == "top"){
            if(stk.empty()){
                cout << -1 << endl;
            }
            else{
                n = stk.top();
                cout << n << endl;
            }
        }
    }

    return 0;
}