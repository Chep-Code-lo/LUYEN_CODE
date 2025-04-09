#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e6+1;
const int MOD = 1e9+7;
int n, x, a[101], dp[N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> x;
    for(int i=0; i<n; ++i)  cin >> a[i];
}
void solve(){
    faster
    //file("");
    input();
    dp[0] = 1;
    for(int i=0; i<x; ++i)
        if(dp[i] != 0)
            for(int j=0; j<n; ++j)
                if(i+a[j] <= x)
                    dp[i+a[j]] = (dp[i] + dp[i+a[j]]) % MOD;
    cout << dp[x];
}
signed main(){
    solve();
    print_time();
}