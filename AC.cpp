#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;

    cin >> T;

    while(T--){
        string str, arr, num = "";
        deque<char> cmd;
        deque<int> target;
        int n;
        bool check = false;
        bool isReverse = false;

        cin >> str;
        cin >> n;
        cin >> arr;

        //명령어 최적화
        //R이 두번 연속 있으면 제거
        for(int i = 0; i < str.size(); i++){
            if(cmd.empty()){
                cmd.push_back(str[i]);
            }
            else{
                if(cmd.back() == 'R'){
                    if(str[i] == 'R'){
                        cmd.pop_back();
                    }
                    else{
                        cmd.push_back(str[i]);
                    }
                }
                else{
                    cmd.push_back(str[i]);
                }
            }
        }

        //숫자 배열 target 덱에 넣기
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] >= '0' && arr[i] <= '9'){
                num += arr[i];
            }
            else if(arr[i] == ',' || arr[i] == ']'){
                if(!num.empty()){    
                    target.push_back(stoi(num));
                    num = "";
                }
            }
        }

        //명령어 수행
        while(!cmd.empty() && !check){
            if(cmd.front() == 'R'){
                isReverse = !isReverse;
            }
            else{    
                if(target.empty()){
                    check = true;
                    break;
                }
                
                if(isReverse){
                    target.pop_back();
                }
                else{
                    target.pop_front();
                }
            }
            cmd.pop_front();
        }

        //결과
        if(check){
            cout << "error" << endl;
        }
        else{
            int size = target.size();

            cout << "[";

            if(isReverse){
                for(int i = 0; i < size; i++){
                    cout << target.back();
                    if(i < size - 1){
                        cout << ",";
                    }
                    target.pop_back();
                }
            }
            else{
                for(int i = 0; i < size; i++){
                    cout << target.front();
                    if(i < size - 1){
                        cout << ",";
                    }
                    target.pop_front();
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}