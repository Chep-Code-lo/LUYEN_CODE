#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6+1;
int n, dp[N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
}
void solve(){
	faster
	//file("");
    input();
    dp[0] = 1;
    for(int i=1; i<=n; ++i)
    	for(int j=1; j<=6 && i-j>=0; ++j)
    		dp[i] = (dp[i] + dp[i-j]) % MOD;
    cout << dp[n];
}
signed main(){
    solve();
    print_time();
}
