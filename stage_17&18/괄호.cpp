#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int T;
    
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        string s;
        stack<char> stk;

        cin >> s;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(stk.empty()){
                stk.push(c);
            }
            else{
                if(c == '('){
                    stk.push(c);
                }
                else if(c == ')'){
                    if(stk.top() == '('){
                        stk.pop();
                    }
                    else{
                        stk.push(c);
                    }
                }
            }
        }

        if(stk.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}