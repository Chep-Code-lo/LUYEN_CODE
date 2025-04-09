#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
const int INF = 1e18; 
int n, x, k;
vector<int> a;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> x >> k;
    a.resize(n);
    for(int i=0; i<n; ++i)	cin >> a[i];
}
class SlidingWindow{
public:
    multiset<int> left, right;
    int sum_left = 0, sum_right = 0;
    // Cân bằng 2 multiset sao cho: left.size() == right.size() hoặc left.size() == right.size() + 1.
    void rebalance(){
        while(left.size() > right.size() + 1){
            auto it = prev(left.end());
            int val = *it;
            left.erase(it);
            sum_left -= val;
            right.insert(val);
            sum_right += val;
        }
        while(left.size() < right.size()){
            auto it = right.begin();
            int val = *it;
            right.erase(it);
            sum_right -= val;
            left.insert(val);
            sum_left += val;
        }
    }
    // Thêm một giá trị vào cửa sổ
    void add(int val){
        if(left.empty() || val <= *prev(left.end())){
            left.insert(val);
            sum_left += val;
        }else{
            right.insert(val);
            sum_right += val;
        }
        rebalance();
    }
    // Xoá một giá trị khỏi cửa sổ
    void remove(int val){
        auto it = left.find(val);
        if(it != left.end()){
            left.erase(it);
            sum_left -= val;
        }else{
            auto it2 = right.find(val);
            if(it2 != right.end()){
                right.erase(it2);
                sum_right -= val;
            }
        }
        rebalance();
    }
    // Lấy median (phần tử lớn nhất của left)
    int getMedian(){
        return *prev(left.end());
    }
    // Tính tổng khoảng cách tuyệt đối từ các phần tử đến median
    int getCost(){
        int m = getMedian();
        int cost_left = m * left.size() - sum_left;
        int cost_right = sum_right - m * right.size();
        return cost_left + cost_right;
    }
};
void solve(){
    faster
    input();
    // Tính chi phí biến đổi cho mỗi đoạn con liên tiếp có độ dài x.
    // Số lượng các đoạn con khả dĩ: M = n - x + 1.
    int M = n - x + 1;
    vector<int> segCost(M, 0);
    SlidingWindow sw;
    for(int i=0; i<n; ++i){
        sw.add(a[i]);
        if (i >= x - 1){
            int start = i - x + 1;
            segCost[start] = sw.getCost();
            sw.remove(a[start]);
        }
    }
    // Chọn k đoạn không giao nhau có tổng chi phí nhỏ nhất.
    // dp[i][j]: chi phí tối thiểu khi đã xét các đoạn có chỉ số khởi đầu < i và đã chọn j đoạn.
    vector<vector<int>> dp(M + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    int ans = INF;
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == INF) continue;
            // Tùy chọn: bỏ qua đoạn bắt đầu tại i
            if(i < M)
               	dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            // Nếu chưa chọn đủ k đoạn, chọn đoạn bắt đầu tại i
            if(i < M && j < k){
                int nextIndex = i + x; // Đảm bảo các đoạn không giao nhau
                int newCost = dp[i][j] + segCost[i];
                if(nextIndex <= M){
                    dp[nextIndex][j+1] = min(dp[nextIndex][j+1], newCost);
                }else{
                    // Nếu vượt qua phạm vi, chỉ chấp nhận nếu đã chọn đúng k đoạn.
                    if(j + 1 == k)
                        ans = min(ans, newCost);
                }
            }
        }
    }
    cout << min(ans, dp[M][k]);
}
signed main(){
    solve();
    print_time();
}
