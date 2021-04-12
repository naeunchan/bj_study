#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool asc(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void){
    int r, c, k, count = 0;
    int rowCount = 3, colCount = 3;
    vector<vector<int>> matrix(100, vector<int>(100, 0));

    cin >> r >> c >> k;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> matrix[i][j];
        }
    }

    while(count++ <= 100){
        if(matrix[r - 1][c - 1] == k){
            cout << count - 1;
            return 0;
        }

        if(rowCount >= colCount){
            for(int i = 0; i < rowCount; i++){
                vector<pair<int, int>> tmpArr;
                map<int, int> m;
                int index = 0;
                
                for(int j = 0; j < 100; j++){
                    if(matrix[i][j] > 0){
                        m[matrix[i][j]]++;
                    }
                }

                for(auto itr = m.begin(); itr != m.end(); itr++){
                    tmpArr.push_back({itr->first, itr->second});
                }

                sort(tmpArr.begin(), tmpArr.end(), asc);

                for(int j = 0; j < tmpArr.size(); j++){
                    matrix[i][index++] = tmpArr[j].first;
                    matrix[i][index++] = tmpArr[j].second;
                }
                
                for(int j = tmpArr.size() * 2; j < 100; j++){
                	matrix[i][index++] = 0;
                }

                colCount = colCount < tmpArr.size() * 2 ? tmpArr.size() * 2 : colCount;
            }
        }
        else{
            for(int i = 0; i < colCount; i++){
                vector<pair<int, int>> tmpArr;
                map<int, int> m;
                int index = 0;
                
                for(int j = 0; j < 100; j++){
                    if(matrix[j][i] > 0){
                        m[matrix[j][i]]++;
                    }
                }

                for(auto itr = m.begin(); itr != m.end(); itr++){
                    tmpArr.push_back({itr->first, itr->second});
                }

                sort(tmpArr.begin(), tmpArr.end(), asc);
				
                for(int j = 0; j < tmpArr.size(); j++){
                    matrix[index++][i] = tmpArr[j].first;
                    matrix[index++][i] = tmpArr[j].second;
                }
                
                for(int j = tmpArr.size() * 2; j < 100; j++){
                	matrix[index++][i] = 0;	
                }

                rowCount = rowCount < tmpArr.size() * 2 ? tmpArr.size() * 2 : rowCount;
            }
        }
    }

    cout << -1;

    return 0;
}