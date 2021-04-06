#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

bool desc(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second > b.second;
}

int main(void){
    int N, M, K, ans = 0;
    int directX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int directY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    //tree = 현재 심어져 있는 나무
    //dead = 죽은 나무
    //breeding = 가을에 번식하는 나무
    //tree에 있는 나무는 양분을 먹으면 breeding로, 양분을 먹지 못하고 죽은 나무는 dead에 넣는다.
    deque<pair<pair<int, int>, int>> tree;
    queue<pair<pair<int, int>, int>> dead;
    queue<pair<int, int>> breeding;

    cin >> N >> M >> K;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 5));
    vector<vector<int>> nourishment(N + 1, vector<int>(N + 1, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> nourishment[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        int x, y, z;

        cin >> x >> y >> z;
        tree.push_back({{x, y}, z});
    }

    while(K--){
        //spring
        int size = tree.size();

        for(int i = 0; i < size; i++){
            int x = tree.front().first.first;
            int y = tree.front().first.second;
            int age = tree.front().second;

            tree.pop_front();

            if(board[x][y] < age){
                dead.push({{x, y}, age});
            }
            else{
                board[x][y] -= age;
                age++;

                //나무의 나이가 5의 배수이면 breeding 큐에 삽입
                if(!(age % 5)){
                    breeding.push({x, y});
                }
                tree.push_back({{x, y}, age});
            }
        }

        //summer
        while(!dead.empty()){
            int x = dead.front().first.first;
            int y = dead.front().first.second;
            int age = dead.front().second;
            
            dead.pop();

            board[x][y] += age / 2;
        }

        //fall
        while(!breeding.empty()){
            int x = breeding.front().first;
            int y = breeding.front().second;

            breeding.pop();

            for(int i = 0; i < 8; i++){
                int nx = x + directX[i];
                int ny = y + directY[i];

                if(nx > 0 && nx <= N && ny > 0 && ny <= N){
                    tree.push_front({{nx, ny}, 1});
                }
            }
        }

        //winter
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                board[i][j] += nourishment[i][j];
            }
        }
        
        if(tree.empty()){
            break;
        }
    }

    cout << tree.size();
    
    return 0;
}