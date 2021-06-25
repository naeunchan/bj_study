#include <iostream>
#include <queue>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	queue<int> q;

	cin >> N;

	while(N--){
		string s;
		int n;

		cin >> s;

		if(s == "push"){
			cin >> n;
			q.push(n);
		}
		else if(s == "pop"){
			if(q.empty()){
				cout << -1 << "\n";
			}
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if(s == "size"){
			if(q.empty()){
				cout << 0 << "\n";
			}
			else{
				cout << q.size() << "\n";
			}
		}
		else if(s == "empty"){
			if(q.empty()){
				cout << 1 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		else if(s == "front"){
			if(q.empty()){
				cout << -1 << "\n";
			}
			else{
				cout << q.front() << "\n";
			}
		}
		else if(s == "back"){
			if(q.empty()){
				cout << -1 << "\n";
			}
			else{
				cout << q.back() << "\n";
			}
		}
	}

	return 0;	
}