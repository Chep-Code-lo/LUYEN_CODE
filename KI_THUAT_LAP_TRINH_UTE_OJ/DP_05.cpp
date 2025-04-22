#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
int n;
vector<int> x, f_val; 
void print_time(){
    cerr << "Time elapsed: " << TIME << "s.\n";
}
void input(){
    cin >> n;
    x.resize(n+1);
    f_val.resize(n+1);
    for(int i=1; i<=n; ++i)    cin >> x[i];
    for(int i=1; i<=n; ++i)    cin >> f_val[i];
}
/*
  dp[i][j]: số rô-bốt tối đa có thể phá hủy từ giây i đến giây n, 
            với trạng thái lúc bắt đầu giây i là đã tích điện được j giây.
  Công thức chuyển:
    dp[i][j] = max( dp[i+1][j+1]  (không kích hoạt EMP tại giây i),
                    min(x[i], f_val[j]) + dp[i+1][1] (kích hoạt EMP tại giây i) ).
  Điều kiện biên: dp[n+1][j] = 0, với mọi j.
  Kết quả cần tìm: dp[1][1].
*/
void solve(){
    faster
    input();
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int i = n; i >= 1; i--){
        // Với mỗi trạng thái tích điện j có thể từ 1 đến n.
        for(int j = 1; j<=n; j++){
            // Không kích hoạt EMP tại giây i: chỉ tăng thời gian tích điện.
            int option1 = dp[i+1][j+1];
            // Kích hoạt EMP tại giây i: phá hủy min(x[i], f_val[j]) rô-bốt, sau đó trạng thái reset về 1.
            int option2 = min(x[i], f_val[j]) + dp[i+1][1];
            dp[i][j] = max(option1, option2);
        }
    }
    cout << dp[1][1];
}
signed main(){
    solve();
    print_time();
}
