#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 5e4+1;
/*  Theo bài toán thì thì tìm cặp (i, j) với i<j và a[j] - a[i] đạt max
*/
int n, a[N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=1; i<=n; ++i)	cin >> a[i];
}
void solve(){
	faster
	//file("");
    input();
    vector<int> dp_no(n+1, 0), dp_yes(n+1, 0);
    dp_no[0] = 0;
    dp_yes[0] = -1e9;
    dp_yes[1] = -a[1];
    dp_no[1]  = 0;
    for(int i=2; i<=n; ++i){
        dp_no[i] = max(dp_no[i-1], dp_yes[i-1] + a[i]);
        dp_yes[i] = max(dp_yes[i-1], -a[i]);
    }
    int ans = dp_no[n];
    cout << max(ans, 0LL);
}
signed main(){
    solve();
    print_time();
}
