#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 5e5;
long n, ans, a[N];
vector<long>dp(N, 1e9);
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = -1e9;
    for(int i=1; i<=n; ++i){
        long k = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[k] = a[i];
        ans = max(ans, k);
    }
    cout << ans;
}