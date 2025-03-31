#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
}
int count_divisors(int n){
	int cnt = 0;
	for(int i=1; i*i<=n; ++i)
		if(n%i == 0){
			cnt++;
			if(i != n/i) cnt++;
		}
	return cnt;
}
void solve(){
	faster
	//file("");
    input();
    cout << count_divisors(n);
}
signed main(){
    solve();
    time();
}
