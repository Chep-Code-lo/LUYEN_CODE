#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int MOD = 1e9 + 7;
int n;
vector<int>a;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; ++i)  cin >> a[i];
}
int power_of_two(int k){
    int res = 1, base = 2;
    while(k > 0){
        if(k%2 == 1)
            res = (res*base)%MOD;
        base = (base*base)%MOD;
        k /= 2;
    }
    return res;
}
void solve(){
    faster
    //file("");
    input();
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0; i<n; ++i){
        int count_max = power_of_two(i);
        int count_min = power_of_two(n-i-1);
        int temp = (a[i]*(count_max - count_min + MOD))%MOD;
        ans = (ans + temp) % MOD;
    }
    cout << ans;
}
signed main(){
    solve();
    time();
}
