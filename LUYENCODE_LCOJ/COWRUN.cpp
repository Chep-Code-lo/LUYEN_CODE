// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e4+5;
const int MOD = 1e9+7;
int n, m, a[N], dp[N][505];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)  cin >> a[i];
    for(int i=1; i<=n; ++i){
        int lim = min(i, m);
        for(int j=1; j<=lim; ++j)    dp[i][j] = dp[i-1][j-1] + a[i];
        dp[i][0] = dp[i-1][0];
        for(int j=1; j<=lim; ++j){
            dp[i][0] = max(dp[i][0] , dp[i-j][j]);
            //cout << dp[i][0] << " ";
        }
    }
    cout << dp[n][0];
}