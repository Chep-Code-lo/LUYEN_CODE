#include <iostream>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5+1;
int n, ans, f[N][7][7];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
}
void dp(){
	if(n == 0){
		cout << 1;
		return;
	}
	f[0][0][0] = 1;
	for(int i=0; i<=n; ++i)
		for(int j=0; j<7; ++j)
			for(int k=0; k<7; ++k){
				if(f[i][j][k] == 0) continue;
				for(int l=1; l<=6; ++l){
					if(i+l > n)	continue;
					if(j == k && k == l)	continue;
					f[i+l][l][j] = (f[i+l][l][j] + f[i][j][k]) % MOD; 
				}
			}
	for(int j=0; j<7; ++j)
		for(int k=0; k<7; ++k)
			ans = (ans + f[n][j][k]) % MOD;
	cout << ans;
}
void solve(){
	faster
	//file("");
    input();
    dp();
}
signed main(){
    solve();
    time();
}
