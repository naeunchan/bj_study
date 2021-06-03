#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string answer = "";
vector<string> board;

void daq(int x, int y, int N){
	char start = board[x][y];
	int half = N / 2;

	for(int i = x; i < x + N; i++){
		for(int j = y; j < y + N; j++){
			if(board[i][j] != start){
				answer += "(";
				daq(x, y, half);
				daq(x, y + half, half);
				daq(x + half, y, half);
				daq(x + half, y + half, half);
				answer += ")";
				return;
			}
		}
	}

	answer += start;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for(int i = 0; i < N; i++){
		string s;

		cin >> s;

		board.push_back(s);
	}

	daq(0, 0, N);

	cout << answer;

	return 0;
}