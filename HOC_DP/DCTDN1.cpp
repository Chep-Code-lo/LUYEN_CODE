#include<iostream>
#include<vector>
using namespace std;
int n, ans, a[1003];
vector<int>dp(1003, 1e9);
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = -1e9;
    for(int i=1; i<=n; ++i){
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        ans = max(ans, pos);
    }
    cout << ans << "\n";
}