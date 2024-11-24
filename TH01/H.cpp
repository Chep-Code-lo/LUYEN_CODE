#include <iostream>
using namespace std;
int m, n, k, a[50][50];
int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) cin >> a[i][j];
    int count = 0;
    for(int i=0; i<m; ++i){
        int pos = 0; 
        for(int j=0; j<n; ++j){
            if(a[i][j] == 0)
                pos++;
            else
                pos = 0;
            if(pos == k){
                count++;
                pos = pos - 1; 
            }
        }
    }
    cout << count;
}