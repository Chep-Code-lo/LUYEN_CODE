//Cre: Chat GPT
#include <iostream>
#include <vector>
using namespace std;
bool isExtreme(const vector<vector<int>>& a, int m, int n, int i, int j) {
    int current = a[i][j];
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool isMax = true, isMin = true;
    for (int d = 0; d < 8; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            if (current <= a[ni][nj]) isMax = false;
            if (current >= a[ni][nj]) isMin = false;
        }
    }
    return isMax || isMin;
}
int m, n, sum;
int main(){
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i<m; ++i)
        for (int j = 0; j<n; ++j) cin >> a[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isExtreme(a, m, n, i, j)) {
                sum += a[i][j];
            }
        }
    }
    cout << sum ;
}