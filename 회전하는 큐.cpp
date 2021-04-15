#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void){
    int N, M, ans = 0, index = 0;
    deque<int> d;
    vector<int> v;

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        d.push_back(i);
    }

    for(int i = 0; i < M; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    while(index < M){
        if(d.front() == v[index]){
            d.pop_front();
            index++;
        }
        else{
            int diff = find(d.begin(), d.end(), v[index]) - d.begin();
            bool check =  diff < d.size() - diff ? true : false;

            if(check){
                for(int i = 0; i < diff; i++){
                    d.push_back(d.front());
                    d.pop_front();
                }
            }
            else{
                diff = d.size() - diff;
                for(int i = 0; i < diff; i++){
                    d.push_front(d.back());
                    d.pop_back();
                }
            }
            
            ans += diff;
        }
    }

    cout << ans;
    
    return 0;
}