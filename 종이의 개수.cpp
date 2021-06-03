#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int answer[3] = {0, };
vector<vector<int>> board(pow(3, 7), vector<int>(pow(3, 7), 0));

void daq(int x, int y, int N){
	int start = board[x][y];
	int divided = N / 3;

	for(int i = x; i < x + N; i++){
		for(int j = y; j < y + N; j++){
			if(board[i][j] != start){
				for(int k = 0; k < 3; k++){
					daq(x + (divided * k), y, divided);
					daq(x + (divided * k), y + divided, divided);
					daq(x + (divided * k), (y + divided * 2), divided);
				}
				return;
			}
		}
	}

	if(start == -1){
		answer[0]++;
	}
	else if(start == 0){
		answer[1]++;
	}
	else{
		answer[2]++;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}

	daq(0, 0, N);

	cout << answer[0] << "\n" << answer[1] << "\n" << answer[2];

	return 0;
}