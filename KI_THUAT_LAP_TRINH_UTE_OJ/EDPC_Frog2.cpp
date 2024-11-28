#include<iostream>
#include<vector>
#define N int(1e5+5)
using namespace std;
int n, k, a[N];
vector<int>dp(N, 1e9);
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[1] = 0;
    for(int i=2; i<=n; ++i)
        for(int j=1; j<=k; ++j)
            if(i - j >= 1)
                dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
    cout << dp[n] << "\n";
}
