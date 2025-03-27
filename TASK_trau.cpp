#include <iostream>
#include <math.h>
#include <vector>
//#define int long long
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
    file_trau("TASK");
    input();
    if(maxx < m){
        cout << maxx;
        return;
    }
    for(int i=0; i<n; ++i){
        int b = a[i];
        vector<bool>dp(m, false);
        dp[0] = true;
        for(int j=0; j<n; ++j){
            if(j == i) continue;
            int w = a[j];
            for(int s=m-1-w; s>=0; --s)
                if(dp[s])
                    dp[s+w] = true;
            }
        int low = max(0, m-b);
        for(int s = low; s<m; ++s)
            if(dp[s])
                ans = max(ans, s+b);
    }
    cout << ans;
}
signed main(){
    solve();
    time();
}
