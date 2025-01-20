// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, w[5005], v[5005], dp[5005][5005];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> w[i] >> v[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    cout << dp[n][m];
}