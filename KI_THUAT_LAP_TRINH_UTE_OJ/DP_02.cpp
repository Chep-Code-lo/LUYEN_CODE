#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e3+1;
int n, m, a[N], b[N], dp[N][2];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> m;
	for(int i=0; i<n; ++i)	cin >> a[i];
	for(int i=0; i<n; ++i)	cin >> b[i];
}
void solve(){
	faster
	//file("");
    input();
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    for(int i=1; i<n; ++i){
    	dp[i][0] = min(dp[i-1][0] + a[i], dp[i-1][1] + m + a[i]);
    	dp[i][1] = min(dp[i-1][1] + b[i], dp[i-1][0] + m + b[i]);
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
}
signed main(){
    solve();
    print_time();
}
