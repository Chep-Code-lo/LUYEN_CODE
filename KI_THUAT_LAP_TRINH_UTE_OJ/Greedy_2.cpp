#include <iostream>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
/*	Ý tưởng : Theo đề bài ta có được phép tính ans += 100*rj^t -> để cho ans min thì rj max và t min
	Thuật toán : - Sắp xếp giảm dần và tính theo phép tính đề cung cấp
				 - Đối với phép tính lũy thừa nên dùng bin pow để thuật tiện cho bài có giới hạn lớn

*/
int n, ans, a[11];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
int bin_pow(int a, int b){
	int res = 1;
	while(b > 0){
		if(b&1)	// Kiểm tra bit cuối cùng có là 1 không -> số lẻ
			res *= a;
		a *= a;
		b >>= 1; // Dịch b một bít sang phải (tức là chia cho 2)
	}
	return res;
}
void input(){
	cin >> n;
	for(int i=1; i<=n; ++i)	cin >> a[i];
	sort(a+1, a+n+1, greater<int>());
}
void solve(){
	faster
	//file("");
    input();
    for(int i=1; i<=n; ++i)
    	ans += 100*bin_pow(a[i], i);
    cout << ans;
}
signed main(){
    solve();
    time();
}
