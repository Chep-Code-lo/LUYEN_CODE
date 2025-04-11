#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
}
void solve(){
    faster
    input();
    vector<int> d(n+1), dp(n+1, 0);
    for(int i=1; i<=n; ++i)	cin >> d[i];
    // Khởi tạo dp: sự kiện i có thể bắt đầu được quan sát nếu khoảng cách từ 0 đến d[i] không vượt quá i (thời gian ban đầu)
    for(int i = 1; i <= n; i++)
        if(llabs(d[i]) <= i) dp[i] = 1;
    // với mọi cặp sự kiện (i, j) sao cho i < j, nếu
    // |d[j] - d[i]| <= (j - i) thì từ sự kiện i có thể quan sát được sự kiện j.
    for(int i=1; i<n; ++i)
        if(dp[i] != -1)
            for(int j=i+1; j<=n; ++j)
                if(llabs(d[j] - d[i]) <= (j - i))
                    dp[j] = max(dp[j], dp[i] + 1);
    cout << dp[n];
}
signed main(){
    solve();
    print_time();
}
