#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, r, c, s[51];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> r >> c;
	for(int i=1; i<=n; ++i)	cin >> s[i];
}
void solve(){
	faster
	//file("");
    input();
    vector<int>dp(n+1, 1e9);
    dp[0] = 0;
    for(int i=0; i<n; ++i){
    	dp[i+1] = min(dp[i+1], dp[i] + r*s[i+1]);
    	int next = (i + 4 <= n ? i + 4 : n);
        dp[next] = min(dp[next], dp[i] + c * 4);
    }
    cout << dp[n];
}
signed main(){
    solve();
    print_time();
}
