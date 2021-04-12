#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int n, current = 1, index = 0;
    stack<int> stk;
    vector<int> v;
    string answer = "";

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    while(current <= n){
        if(stk.empty() || stk.top() != v[index]){
            stk.push(current++);
            answer += "+";
        }

        if(stk.top() == v[index]){
            index++;
            answer += "-";
            stk.pop();
        }
    }
    
    while(!stk.empty()){
    	if(stk.top() == v[index++]){
    		answer += "-";
    		stk.pop();
    	}
    	else{
    		cout << "NO";
    		return 0;
    	}
    }
    
    for(int i = 0; i < answer.size(); i++){
    	cout << answer[i] << "\n";
    }

    return 0;
}