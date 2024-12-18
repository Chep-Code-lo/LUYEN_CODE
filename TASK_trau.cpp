#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;

long long A[1000][1000];
long long max_in_matrix = LLONG_MIN; 
int main() {
    file_trau("TASK");
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            max_in_matrix = max(max_in_matrix, A[i][j]);
        }
    }

    int special_count = 0; 
    
 
    for (int i = 0; i < N; i++) {
        long long max_in_row = LLONG_MIN; 
        
     
        for (int j = 0; j < M; j++) {
            max_in_row = max(max_in_row, A[i][j]);
        }

        
        for (int j = 0; j < M; j++) {
            if (A[i][j] == max_in_row && A[i][j] < max_in_matrix) {
                special_count++; 
            }
        }
    }

    cout << special_count;
    return 0;
}