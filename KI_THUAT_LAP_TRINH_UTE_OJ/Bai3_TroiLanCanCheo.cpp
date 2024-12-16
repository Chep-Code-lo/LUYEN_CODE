/*Cre : BlackboxAI*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int current_value = A[i][j];
            bool is_dominant = true;
            int directions[8][2] = {
                {-2, -2}, {-1, -1}, {-2, 2}, {-1, 1},
                {2, -2}, {1, -1}, {2, 2}, {1, 1}
            };
            for (int d = 0; d < 8; ++d) {
                int ni = i + directions[d][0];
                int nj = j + directions[d][1];
                if (ni >= 0 && ni < M && nj >= 0 && nj < N) {
                    if (current_value <= A[ni][nj]) {
                        is_dominant = false;
                        break;
                    }
                }
            }
            if (is_dominant) 
                count++;
        }
    }

    cout << count << endl;
}