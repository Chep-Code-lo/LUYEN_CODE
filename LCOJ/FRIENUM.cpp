#include <iostream>
#include <map>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, ans;
map<int, int>mp;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int x,i=0; i<n; ++i) cin >> x, mp[x]++;
}
void solve(){
	faster
	//file("");
    input();
    for(auto it : mp)
    	if(it.second > 1)
    		ans += it.second;
    cout << ans;
}
signed main(){
    solve();
    time();
}
