#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int white = 0;
int blue = 0;
vector<vector<int>> board(128, vector<int>(128, 0));

void daq(int x, int y, int N){
	int color = board[x][y];
	int half = N / 2;

	for(int i = x; i < x + N; i++){
		for(int j = y; j < y + N; j++){
			if(board[i][j] != color){
				daq(x, y, half);
				daq(x + half, y, half);
				daq(x, y + half, half);
				daq(x + half, y + half, half);
				return;
			}
		}
	}

	color == 1 ? blue++ : white++;
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

	cout << white << endl;
	cout << blue << endl;

	return 0;
}