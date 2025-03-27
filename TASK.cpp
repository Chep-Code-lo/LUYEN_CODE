#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m, maxx, ans, a[101];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)  cin >> a[i], maxx += a[i];
}
void solve(){
    faster
    file_chuan("TASK");
    input();
    if(maxx < m){
        cout << maxx;
        return;
    }
    vector<bool>dp(maxx+1, false);
    dp[0] = true;
    for(int i=0; i<n; ++i)
        for(int j=maxx; j>=0; --j)
            if(dp[j-a[i]])
                dp[j] = true;
    for(int s=maxx; s>=0; --s)
        if(dp[s])
            for(int i=0; i<n; ++i)
                if(s - a[i] < m && s >= m)
                    ans = max(ans, s);
    cout << ans;
}
signed main(){
    solve();
    time();
}
