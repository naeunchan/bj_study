#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(void){
    int T;

    cin >> T;

    for(int t = 0; t < T; t++){
        int n, m, ans = 1;
        queue<int> q;
        vector<int> v;

        cin >> n >> m;

        for(int i = 0; i < n; i++){
            int tmp;
            
            cin >> tmp;

            q.push(tmp);
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), desc);

        while(1){
            if(v.front() == q.front()){
                if(m == 0){
                    break;
                }
                else{
                    v.erase(v.begin());
                    ans++;
                    q.pop();
                    m--;
                }
            }
            else{
                if(m == 0){
                    m = q.size() - 1;
                }
                else{
                    m--;
                }

                q.push(q.front());
                q.pop();
            }
        }

        cout << ans << endl;
    }

    return 0;
}