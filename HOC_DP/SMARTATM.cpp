#include<iostream>
#include<vector>
using namespace std;
int n, m, a[25];
vector<int>dp(100005, 1e9);
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = 0;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i] <= j)
                dp[j] = min(dp[j], dp[j-a[i]] + 1);
    cout << (dp[m] == 1e9 ? -1 : dp[m]);
}