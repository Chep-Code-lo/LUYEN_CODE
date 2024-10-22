#include<iostream>
using namespace std;
int n, K, res, a[26], dp[26][26][26];
int main(){
    cin >> n >> K;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[1][1][1] = a[1], dp[2][2][1] = a[2];
    for(int i=1; i<=n; ++i)
        for(int k=2; k<=K; ++k)
            for(int j=i+1; j<=n; ++j)
                if(dp[i][j-1][k-1] != 0 || dp[i][j-2][k-1] != 0)
                    dp[i][j][k] = max(dp[i][j-1][k-1] + a[j], dp[i][j-2][k-1] + a[j]);
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            res = max(res, dp[i][j][K]);
    cout << res << "\n";
}