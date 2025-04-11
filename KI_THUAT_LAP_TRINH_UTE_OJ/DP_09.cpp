#include <iostream>
#include <vector>
#include <limits>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
vector<int>c;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	c.resize(n+1);
	for(int i=1; i<=n; ++i)	cin >> c[i];
}
void solve(){
	faster
	//file("");
    input();
    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;
    for(int j=1; j<=n; ++j)
		for(int i=0; i<j; ++i){
			int gap = j - i;
			int access_cost = (int)(gap - 1) * (gap) / 2;
			int candidate = dp[i] + access_cost + c[j];
			if(candidate < dp[j])	dp[j] = candidate;
		}
	cout << dp[n];
}
signed main(){
    solve();
    print_time();
}
