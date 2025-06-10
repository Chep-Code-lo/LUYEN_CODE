#include <iostream>
#include <string>
#include <algorithm>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
int n, a[101], pre[101], f[101][101];
void input(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i]; 
    }
    auto sum = [&](int l, int r) {return pre[r] - pre[l-1];};
    for(int i=2; i<=n; ++i)
        for(int j=1; j+i-1<=n; ++j){
            int r = i+j-1;
            f[j][r] = 1e9;
            for(int k=j; k<r; ++k)
                f[j][r] = min(f[j][r], f[j][k] + f[k+1][r] + sum(j, r));
        }
    cout << f[1][n];
}
void solve(){
    faster
    //file("");
    input();
}
signed main(){
    solve();
    print_time();
}