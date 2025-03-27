#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e6+1;
int n, a[N];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
}
void solve(){
    faster
    //file("");
    input();
    for(int i=2; i<=n; ++i){
        a[i] = a[i-1] + 1;
        if(i%2 == 0)    a[i] = min(a[i], a[i/2] + 1);
        if(i%3 == 0)    a[i] = min(a[i], a[i/3] + 1);
    }
    cout << a[n];
}
signed main(){
    solve();
    time();
}
