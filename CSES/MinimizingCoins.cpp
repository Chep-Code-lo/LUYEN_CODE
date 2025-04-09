#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e6+1;
int n, x, a[101], dp[N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> x;
	for(int i=0; i<n; ++i)	cin >> a[i];
	for(int i=1; i<=x; ++i) 	dp[i] = 1e9;
}
void solve(){
	faster
	//file("");
    input();
    dp[0] = 0;
    for(int i=0; i<n; ++i)
    	for(int j=a[i]; j<=x; ++j)
    		dp[j] = min(dp[j], dp[j-a[i]] + 1);
    cout << (dp[x] == 1e9 ? -1 : dp[x]);
}
signed main(){
    solve();
    print_time();
}
