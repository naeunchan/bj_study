#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    int N, index = 1;
    vector<int> v, tmp;
    map<int, int> m;

    cin >> N;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        
        v.push_back(n);
    }

    tmp = v;
    sort(tmp.begin(), tmp.end());

    for(int i = 0; i < v.size(); i++){
        if(!m[tmp[i]]){
            m[tmp[i]] = index++;
        }
    }

    for(int i = 0; i < N; i++){
        cout << m[v[i]] - 1 << " " ;
    }
    
    return 0;
}