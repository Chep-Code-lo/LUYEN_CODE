#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
/*Ý tưởng : - Ta thấy việc tồn tại lịch trình hợp lệ chỉ phụ thuộc và tổng bit và tổng băng thông -> Không quan trọng thứ tự
			- Với ràng buộc ta có thể luôn sắp xếp các luồng để đảm bảo không vi phạm điều kiện
			- Nếu tổng bit <= tổng băng thông -> đảm bảo có thể gửi tất cả các luồng
			=> Không cần sinh ra các hoán vị để kiểm tra
Thuật toán : - Tính tổng bít , thời gian của tất cả các luồng
			 - Tính tổng băng thông : r*tổng time
			 - So sánh tổng bit vs tổng băng thông*/
int n, r, total_bit, max_time;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> r;
	for(int b, t,i=0; i<n; ++i){
		cin >> b >> t;
		total_bit += b;
		max_time += t;
	}	
}
void solve(){
	faster
	//file("");
    input();
    int ans = r*max_time;
    cout << (total_bit <= ans ? "YES" : "NO");
}
signed main(){
    solve();
    time();
}
