// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
using namespace std;
int n, m, a[505][505], dp[505][505];
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)  cin >> a[i][j];
    dp[0][0] = a[0][0];
    for(int i=1; i<n; ++i)  dp[i][0] = dp[i-1][0] + a[i][0];
    for(int j=1; j<m; ++j)  dp[0][j] = dp[0][j-1] + a[0][j];
    for(int i=1; i<n; ++i)
        for(int j=1; j<m; ++j)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
    cout << dp[n-1][m-1];
}