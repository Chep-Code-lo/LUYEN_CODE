#include<iostream>
using namespace std;
int n, m, x, y, a[102][102];
long long sum;
int main(){
    cin >> n >> m >> x >> y;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) cin >> a[i][j];
    x--, y--;
    for(int i=0; i<n; ++i){
        int j1 = y - (x-i);
        int j2 = y + (x-i);
        if(j1>=0 &&  j1<m)
            sum += a[i][j1];
        if(j2>=0 && j2<m)
            sum += a[i][j2];
    }
    cout << sum - a[x][y];

}
