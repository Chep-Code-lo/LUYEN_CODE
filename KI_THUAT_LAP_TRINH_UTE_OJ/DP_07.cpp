#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name)  freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
vector<int> x, f_val;
void print_time(){
    cerr << "Time elapsed: " << TIME << "s.\n";
}
void input(){
    cin >> n;
    x.resize(n+1);
    f_val.resize(n+1);
    for(int i=1; i <= n; ++i)    cin >> x[i];
    for(int i=1; i<=n; ++i) cin >> f_val[i];
}
/*
  dp[i][j]: lượng dữ liệu tối đa có thể xử lý từ ngày i đến ngày n,
            với trạng thái hệ thống hiện có "tuổi" j (tức là đã hoạt động liên tục j ngày kể từ khởi động lại).
  
  Công thức chuyển:
    dp[i][j] = max( min(x[i], f_val[j]) + dp[i+1][j+1],  dp[i+1][1] ).

  Điều kiện biên: dp[n+1][j] = 0, với mọi j.
  
  Kết quả cần tìm: dp[1][1].
*/
void solve(){
    faster
    input();
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int i = n; i >= 1; i--){
        // Với mỗi trạng thái tích lũy hiện tại j (từ 1 đến n)
        for(int j = 1; j <= n; j++){
            // Lựa chọn 1: Không khởi động lại ngày i
            int option1 = min(x[i], f_val[j]) + dp[i+1][j+1];
            // Lựa chọn 2: Khởi động lại vào ngày i (xử lý 0 dữ liệu hôm đó, reset trạng thái về 1)
            int option2 = dp[i+1][1];
            dp[i][j] = max(option1, option2);
        }
    }
    cout << dp[1][1];
}
signed main(){
    solve();
    print_time();
}
