#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int n;
		
		cin >> n;

		if(n == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
			else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
		}
		else{
			pq.push({abs(n), n});
		}
	}
	return 0;
}