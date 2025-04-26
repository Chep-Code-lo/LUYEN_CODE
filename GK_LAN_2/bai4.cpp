#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, a[1001], dp[1001];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}   
void input(){
    cin >> n;
    for(int i=0; i<n; ++i)	cin >> a[i];
}
void solve(){
    faster
    input();
    int res = -1e9;
    for(int i=0; i<n; ++i){
    	dp[i] = a[i];
    	for(int j=0; j<i; ++j)
    		if((a[j]&1) != (a[i]&1))
    			dp[i] = max(dp[i], dp[j] + a[i]);
    	res = max(res, dp[i]);
    }
    cout << res;
}
signed main(){
    solve();
    time();
}