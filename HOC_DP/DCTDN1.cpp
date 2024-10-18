#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, ans, a[1005];
vector<int>dp(1005, 1e9);
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = -1e9;
    for(int i=1; i<=n; ++i){
        int k = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[k] = a[i];
        ans = max(ans, k);
    }
    cout << ans << "\n";
}
