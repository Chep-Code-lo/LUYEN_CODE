#include<iostream>
#define int long long
using namespace std;
int s, n, res = 1e18, a[103], sum, dp[300005];
signed main(){
    cin >> s >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
    for(int i=1; i<=s+sum; ++i)
        dp[i] = 1e18;
    dp[0] = 0;
    for(int i=1; i<=n; ++i)
        for(int j=a[i]; j<=s+sum; ++j)
            dp[j] = min(dp[j], dp[j-a[i]] + 1);
    for(int i=s; i<=s+sum; ++i)
        res = min(res, dp[i] + dp[i-s]);
    cout << res << "\n";
}