#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e4+1;
int n, l[N], h[N], dp[N][3];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=0; i<n; ++i)	cin >> l[i];
	for(int i=0; i<n; ++i)	cin >> h[i];
}
void solve(){
	faster
	//file("");
    input();
    dp[0][0] = 0;
    dp[0][1] = l[0];
    dp[0][2] = -100000;
    for(int i=1; i<n; ++i){
    	dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    	dp[i][1] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + l[i];
    	dp[i][2] = dp[i-1][0] + h[i];
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
signed main(){
    solve();
    print_time();
}
