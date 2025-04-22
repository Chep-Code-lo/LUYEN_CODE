#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m, cnt, a[100], f[100];
bool avail[100];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> m;
	for(int i=0; i<n; ++i)	cin >> a[i];
	sort(a, a+n);
}
void print(){
	++cnt;
	for(int i=0; i<m; ++i)	cout << f[i] << " ";
	cout << "\n";
}
void backtrack_no_lap(int x){
	if(x == m){
		print();
		return;
	}
	for(int i=0; i<n; ++i){
		if(!avail[i]){
			avail[i] = true;
			f[x] = a[i];
			backtrack_no_lap(x+1);
			avail[i] = false;
		}
	}
}
void backtrack_lap(int x){
	if(x == m){
		print();
		return;
	}
	for(int i=0; i<n; ++i){
		f[x] = a[i];
		backtrack_lap(x+1);
	}
}
void solve(){
	faster
	//file("");
    input();
    backtrack_lap(0); //(Chỉnh hợp lặp)
    backtrack_no_lap(0); //(Chỉnh hợp không lặp)
    cout << cnt << "\n";
}
signed main(){
    solve();
    time();
}
