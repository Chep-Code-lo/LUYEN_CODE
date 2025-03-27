#include <iostream>
#include <string.h>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e6+2;
int n, k, res, current, f[N];
string s;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> k >> s;
}
void solve(){
    faster
    //file("");
    input();
    for(int i=0; i<n; ++i){
        current += f[i];
        if((s[i] - '0') ^ (current % 2) == 0){
            if(i+k > n){
                cout << -1;
                return;
            }
            res++;
            current++;
            f[i]++;
            f[i+k]--;
        }
    }
    cout << res;
}
signed main(){
    solve();
    time();
}
