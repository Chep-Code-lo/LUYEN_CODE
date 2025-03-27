#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
vector<int> times;
void time(){
    cerr << "Time elapsed: " << TIME << "s.\n";
}
void input(){
    cin >> n;
    times.resize(n);
    for(int i=0; i<n; ++i) cin >> times[i];
}
void solve(){
    faster
    //file("");
    input();
    sort(times.begin(), times.end()); 
    int total_time = 0, current_time = 0;
    for(int t : times){
        current_time += t;
        total_time += current_time; 
    }
    cout << total_time << "\n";
}
signed main(){
    solve();
    time();
}
