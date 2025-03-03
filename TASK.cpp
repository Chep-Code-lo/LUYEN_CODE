#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int M = 1e6;
int n, a[M], pre[M];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
}
void Divisors_Sieve(){
    for(int i=1; i<=M; ++i) a[i] = 1;
    for(int i=2; i<=M/2; ++i)
        for(int j=2; j<=M/i; ++j)
            a[i*j]++;
}
void sieve(){
    for(int i=1; i<=M; ++i)
        if(i%3==0 && a[i] == 8)
            pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
}
void solve(){
    faster
    file_chuan("TASK");
    input();
    Divisors_Sieve();
    sieve();
    while(n--){
        int a, b; cin >> a >> b;
        cout << pre[b] - pre[a-1] << "\n";
    }
}
signed main(){
    solve();
    time();
}
