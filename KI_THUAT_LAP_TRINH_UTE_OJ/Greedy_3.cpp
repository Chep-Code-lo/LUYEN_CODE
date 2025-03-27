#include <iostream>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, w, count = 1, current_w, a[1001];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> w;
	for(int i=0; i<n; ++i)	cin >> a[i];
}
void solve(){
	faster
	//file("");
    input();
    for(int i=0; i<n; ++i){
    	if(current_w + a[i] > w)	count++, current_w = a[i];
    	else current_w += a[i];
    }
    cout << count;
}
signed main(){
    solve();
    time();
}
