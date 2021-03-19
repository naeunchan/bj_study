#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(void){
    string input;

    while(1){
        stack<char> stk;
        
        getline(cin, input);

        if(input == "."){
            break;
        }
        else{
            for(int i = 0; i < input.size(); i++){
                if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] == '.') || (input[i] == ' ')){
                    continue;
                }

                if(stk.empty()){
                    stk.push(input[i]);
                }
                else{
                    if(input[i] == '(' || input[i] == '['){
                        stk.push(input[i]);
                    }
                    else if(input[i] == ')'){
                        if(stk.top() == '('){
                            stk.pop();
                        }
                        else{
                            stk.push(input[i]);
                        }
                    }
                    else if(input[i] == ']'){
                        if(stk.top() == '['){
                            stk.pop();
                        }
                        else{
                            stk.push(input[i]);
                        }
                    }
                }
            }

            if(stk.empty()){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    
    return 0;
}