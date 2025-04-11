#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, l, c[101];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> l;
	for(int i=0; i<n; ++i)	cin >> c[i];
}
void solve(){
	faster
	//file("");
    input();
    vector<int>dp(n+1, 1e9);
    dp[n] = 0;
    for(int i=n-1; i>=0; --i){
    	int sum_len = 0;
    	for(int j=i; j<n; ++j){
    		sum_len += c[j];
    		int neede = sum_len + (j-i);
    		if(neede > l) break;
    		int extra = l - neede;
    		int cost = extra*extra;
    		dp[i] = min(dp[i] , cost + dp[j+1]);
    	}
    }
    cout << dp[0];
}
signed main(){
    solve();
    print_time();
}
