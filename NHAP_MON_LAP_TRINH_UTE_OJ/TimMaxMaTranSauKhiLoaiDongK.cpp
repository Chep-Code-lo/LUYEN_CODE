#include<iostream>
using namespace std;
int m, n, k, maxx=-1e9, matrix[101][101];
int main(){
    cin >> m >> n >> k;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) cin >> matrix[i][j];
    for(int i=0; i<m; ++i){
        if(i==k)    continue;
        for(int j=0; j<n; ++j)
            maxx = max(maxx, matrix[i][j]);
    }
    cout << maxx;
}
