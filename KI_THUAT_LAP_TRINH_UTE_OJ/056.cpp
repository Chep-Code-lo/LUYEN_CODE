#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 2e5+1;
int n, k, sum, a[N];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> k;
    for(int i=0; i<n; ++i)  cin >> a[i], sum+= a[i];
}
bool check(int x){
    int total = 0;
    for(int i=0; i<n; ++i)
        total += min(a[i], x);
    return total >= k*x;
}
void binary(){
    int l = 0, r = sum;
    r /= k;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}
void solve(){
    faster
    //file("");
    input();
    binary();
}
signed main(){
    solve();
    time();
}
