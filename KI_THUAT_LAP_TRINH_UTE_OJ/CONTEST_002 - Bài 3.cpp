#include<iostream>
#define int long long
const int N = 1e5+1;
const int MOD = 1e9+7;
using namespace std;
int n, dp[N], dp_a[N], dp_b[N], dp_c[N];
int count_string(int n){
    if(n == 0) return 1;
    if(n == 1) return 3;
    dp[0] = 1, dp[1] = 3;
    dp_a[1] = dp_b[1] = dp_c[1] = 1;
    for(int i=2; i<=n; ++i){
        dp_a[i] = dp[i-1] % MOD;
        dp_b[i] = (dp_b[i-1] + dp_c[i-1]) % MOD;
        dp_c[i] = dp[i-1] % MOD;
        dp[i] = (dp_a[i] + dp_b[i] + dp_c[i]) % MOD;
    }
    return dp[n];
}
signed main(){
    cin >> n;
    cout << count_string(n);
}