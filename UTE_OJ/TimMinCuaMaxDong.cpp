#include<iostream>
#include<algorithm>
using namespace std;
int m, n, minn = 1e9, matrix[103][103];
int main(){
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) cin >> matrix[i][j];
    for(int i=0; i<m; ++i){
        int maxx = -1e9;
        for(int j=0; j<n; ++j)
            maxx = max(maxx, matrix[i][j]);
        minn = min(minn, maxx);
    }
    cout << minn;    
}