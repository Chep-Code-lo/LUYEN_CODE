#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
/*Ý tưởng : - Chọn nhà đầu tiên chưa được phủ sóng và đặt trạm xa nhất trong phạm vi b vì có thể giảm thiểu số trạm cần đặt
			- Cập nhật phạm vi phủ sóng của trạm vừa đặt 
			- Tìm nhà tiếp theo chưa được phủ sóng và lặp lại
 Thuật toán : - Duyệt và chọn nhà đầu tiên chưa phủ sóng làm điểm bắt đầu
 			  - Tìm nhà xa nhất trong phạm vi b
 			  - Lặp lại thao tác*/
const int N = 1e4+1;
int B, n, b, count, pos, a[N];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> B >> n >> b;
	for(int i=0; i<n; ++i)	cin >> a[i];
}
void solve(){
	faster
	//file("");
    input();
    int i = 0;
    while(i < n){
    	count += 1;
    	pos = a[i];
    	while(i < n && a[i] <= pos + b)	i++;
    	pos = a[i-1];
    	while(i < n && a[i] <= pos + b)	i++;
    }
    cout << count;
}
signed main(){
    solve();
    time();
}
