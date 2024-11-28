#include<iostream>
#include<algorithm>
#include<vector>
#define N int(1e6)
using namespace std;
int n, a[N+1], ans;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    vector<int>dp(N+1, 1e9), res(N+1);
    dp[0] = -1e9;
    for(int i=1; i<=n; ++i){
        int x = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[x] = a[i];
        res[i] = x;
        ans = max(ans, x);
    }
    cout << ans << "\n";
    /*vector<int>v;
    for(int i=n; i>=1; i--){
        if(res[i] == ans)
            v.push_back(i), ans--;
    }
    for(int i=v.size() - 1; i>=0; i--)
        cout << v[i] << " ";*/
}