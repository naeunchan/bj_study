#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int N;
	
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		int n;

		cin >> n;

		if(maxHeap.empty()){
			maxHeap.push(n);
		}
		else if(maxHeap.size() == minHeap.size()){
			maxHeap.push(n);
		}
		else{
			minHeap.push(n);
		}

		if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
			int maxTop = maxHeap.top();
			int minTop = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(minTop);
			minHeap.push(maxTop);
		}

		cout << maxHeap.top() << "\n";
	}

	return 0;
}