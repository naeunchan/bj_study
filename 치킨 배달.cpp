#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int M;
int ans = INT_MAX;
vector<vector<int>> board(51, vector<int>(51, 0));
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];

            if(board[i][j] == 1){
                house.push_back({i, j});
            }
            else if(board[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> ind(M, 1);

    for(int i = M; i < chicken.size(); i++){
        ind.push_back(0);
    }

    sort(ind.begin(), ind.end());
    

    do{
        int sum = 0;

        for(int i = 0; i < house.size(); i++){
            int tmp = INT_MAX;

            for(int j = 0; j < ind.size(); j++){
                if(ind[j]){
                    tmp = tmp < abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second) ? tmp : abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                }
            }
            sum += tmp;
        }

        ans = ans < sum ? ans : sum;
    }while(next_permutation(ind.begin(), ind.end()));

    cout << ans;

    return 0;
}