#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int m, n, matrix[102][102], max_in_row[102];
vector<pair<int, int>>poss;
int pos[102 * 102][2];
int pos_count = 0;
int main() {
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin >> matrix[i][j];
    for(int i=0; i<m; ++i)
        max_in_row[i] = *max_element(matrix[i], matrix[i]+n);
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) {
            if(matrix[i][j] == max_in_row[i]){
                bool is_min_in_col = true;
                for (int k = 0; k < m; ++k)
                    if (matrix[k][j] < matrix[i][j]){
                        is_min_in_col = false;
                        break;
                    }
                if (is_min_in_col){
                    pos[pos_count][0] = i + 1;
                    pos[pos_count][1] = j + 1;
                    pos_count++;
                    //poss.push_back({i + 1, j + 1});
                }
            }
        }
    cout << pos_count << "\n";
    for (int i = 0; i < pos_count; ++i)
        cout << pos[i][0] << " " << pos[i][1] << "\n";
    /*cout << poss.size() << endl;
    for (auto it : poss)
        cout << it.first << " " << it.second << "\n";*/
}
