#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m, a[1001][1001];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> m;
	for(int i=0; i<n ; ++i)
		for(int j=0; j<m; ++j)	cin >> a[i][j];
}
void solve(){
	faster
	//file("");
    input();
    int cnt = 0;
    for(int i=1; i<n-1 ; ++i)
		for(int j=1; j<m-1; ++j){
			int x = a[i][j];
			if(x <= a[i-1][j] || x <= a[i+1][j] || x <= a[i][j-1]|| x <= a[i][j+1])
				continue;
			if(x >= a[i-1][j-1] || x >= a[i-1][j+1] || x >= a[i+1][j-1] || x >= a[i+1][j+1])
				continue;
			cnt++;
		}
	cout << cnt;
}
signed main(){
    solve();
    print_time();
}
