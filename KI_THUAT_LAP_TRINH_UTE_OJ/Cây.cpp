#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
vector<int> x, h;
void time(){
    cerr << "Time elapsed: " << TIME << "s.\n";
}
void input(){
    cin >> n;
    x.resize(n), h.resize(n);
    for(int i=0; i<n; ++i) cin >> x[i];
    for(int i=0; i<n; ++i) cin >> h[i];
}
void solve(){
    faster
    input();
    if(n == 1){
        cout << 1;
        return;
    }
    int count = 1;
    int last_pos = x[0];
    for(int i=1; i<n-1; i++){
        if(x[i] - h[i] + 1 > last_pos){
            count++;
            last_pos = x[i];
        }else if(x[i] + h[i] - 1 < x[i+1]){
            count++;
            last_pos = x[i] + h[i] + 1;
        }else
            last_pos = x[i];
    }
    count++;
    cout << count;
}
signed main(){
    solve();
    time();
}
