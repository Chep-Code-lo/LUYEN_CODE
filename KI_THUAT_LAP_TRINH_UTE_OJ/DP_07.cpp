#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 101;
int n, a[N], b[N], dp_a[N], dp_b[N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
    for(int i=1; i<=n; ++i)  cin >> a[i];
    for(int i=1; i<=n; ++i)  cin >> b[i];
}
void solve(){
    faster
    //file("");
    input();
    if(n >= 1)    dp_a[1] = a[1], dp_b[1] = b[1];
    if(n >= 2)    dp_a[2] = dp_a[1] + a[2], dp_b[2] = dp_b[1] + b[2];
    for(int i=3; i<=n; ++i){
        dp_a[i] = max(dp_a[i-1] + a[i], dp_b[i-2] + a[i]);
        dp_b[i] = max(dp_b[i-1] + b[i], dp_a[i-2] + b[i]);
    }
    cout << max(dp_a[n], dp_b[n]);
}
signed main(){
    solve();
    print_time();
}
