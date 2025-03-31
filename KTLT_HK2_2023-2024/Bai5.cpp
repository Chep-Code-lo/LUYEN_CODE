#include <iostream>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
int m, n, x, y, k, a[1001][1001];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> m >> n >> x >> y >> k;
	x--; y--;
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)	cin >> a[i][j];
}
bool is_val(int x, int y, int m, int n){
	return (x >= 0 && x < m && y >= 0 && y < n);
}
bool is_ok(int x , int y, int m, int n){
	return (x == 0 || y == 0 || x == m - 1 || y == n - 1);
}
void solve(){
	faster
	//file("");
    input();
    int t = 0;
    if(is_ok(x, y, m, n)){
    	cout << "YES" << "\n" << t;
    	return;
    }
    int cur = a[x][y];
    while(t < k){
    	int min_h = 1e9;
    	int next_row = -1, next_col = -1;
    	for(int d=0; d<8; ++d){
    		int ni = x + dir[d][0];
    		int nj = y + dir[d][1];
    		if(is_val(ni, nj, m, n))
    			if(a[ni][nj] < min_h){
    				min_h = a[ni][nj];
    				next_row = ni;
    				next_col = nj;
    			}
    	}
    	x = next_row, y = next_col, t++;
    	if(is_ok(x, y, m, n)){
    		cout << "YES" << "\n" << t;
    		return; 
    	}
    }
    cout << "NO" << "\n" << x+1 << " " << y+1;
}
signed main(){
    solve();
    time();
}
