#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, x;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> x;
}
void solve(){
	faster
	//file("");
    input();
    if(x > n*n){
    	cout << 0;
    	return;
    }
    int ans = 0;
    for(int i=1; i*i <= x && i <=n; ++i)
    	if(x%i == 0){
    		int j = x / i;
    		if(j <= n)
    			ans += (i == j ? 1 : 2);
    	}
    cout << ans;
}
signed main(){
    solve();
    print_time();
}
