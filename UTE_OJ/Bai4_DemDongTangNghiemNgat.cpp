#include<iostream>
using namespace std;
int m, n, cnt, matrix[55][55];
int main(){
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) cin >> matrix[i][j];
    for(int i=0; i<m; ++i){
        bool check = true;
        for(int j=1; j<n; ++j)
            if(matrix[i][j-1] >= matrix[i][j]){
                check =false;
                break;
            }
        if(check)   cnt++;
    }
    cout << cnt;
}
/*4   5
1   2   3   4   15
2   3   5   6   12
3   4   5   6   5
3   5   7   6   20*/