#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n;
void timeElapsed(){
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s.\n";
}
class Swim{
public:
    int swim, bike, run;
    Swim(int s, int b, int r) : swim(s), bike(b), run(r) {}
    static bool cmp(const Swim &a, const Swim &b){
        return (a.bike + a.run) > (b.bike + b.run);
    }
};
vector<Swim> a;
void input(){
    cin >> n;
    for(int i=0; i<n; ++i){
        int s, b, r; cin >> s >> b >> r;
        a.emplace_back(s, b, r);
    }
    sort(a.begin(), a.end(), Swim::cmp);
}
void solve(){
    faster
    input();
    int current_sum = 0, ans = 0;
    for(const auto &x : a){
        current_sum += x.swim;
        ans = max(ans, current_sum + x.bike + x.run);
    }
    cout << ans;
}
signed main(){
    solve();
    timeElapsed();
}
