#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> height(9, false);
vector<bool> check(9, false);
bool isFinished = false;

void dfs(int sum, int cnt){
	if(cnt == 7){
		if(sum == 100){
			for(int i = 0; i < 9; i++){
				if(check[i]){
					cout << height[i] << endl;
				}
			}
			isFinished = true;
		}
		return;
	}

	for(int i = 0; i < 9; i++){
		if(!check[i]){
			check[i] = true;
			dfs(sum + height[i], cnt + 1);
			check[i] = false;
			
			if(isFinished){
				return;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for(int i = 0; i < 9; i++){
		cin >> height[i];
	}

	sort(height.begin(), height.end());

	for(int i = 0; i < 9; i++){
		check[i] = true;
		dfs(height[i], 1);
		check[i] = false;
		
		if(isFinished){
			return 0;
		}
	}

	return 0;
}