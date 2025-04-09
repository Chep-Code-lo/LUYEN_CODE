#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e5+1;
int n, minn = 1e9, a[N];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=0; i<n; ++i)	cin >> a[i];
	sort(a, a+n);
}
void solve(){
	faster
	//file("");
    input();
    for(int i=0; i<n-1; ++i)
    	minn = min(minn, a[i+1] - a[i]);
    cout << minn;
}
signed main(){
    solve();
    time();
}
