#include<iostream>
#include<algorithm> 
#define N int(1e5+5)
using namespace std;
long long n, maxx, a[N], b[N], c[N], dp[N][3];
signed main(){
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    for(int i=2; i<=n; ++i){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);
    }
    maxx = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << maxx << "\n";
}