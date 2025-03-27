#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m, maxx, a[101], dp[101][2001];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)  cin >> a[i], maxx = max(maxx, a[i]);
    for(int i=1; i<=n; ++i)
        if(a[i] == maxx){
            a[i] = 0;
            break;
        }
}
void solve(){
    faster
    //file("");
    input();
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=m; ++j){
            dp[i][j] = dp[i-1][j];
            if(j > a[i])
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + a[i]);
        }
    cout << dp[n][m] + maxx;
}
signed main(){
    solve();
    time();
}
