#include<iostream>
using namespace std;
int n, ans, a[1003], dp[1003];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        if(a[i] > 0)
            dp[i] = max(dp[i-1], dp[i-1]+1);
        else dp[i] = 0;
    }
    for(int i=1; i<=n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}