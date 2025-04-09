#include <iostream>
#include <vector>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e3+1;
int n, degree[N], a[N][N];
vector<int>treo, co;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)	cin >> a[i][j];
}
void edge(){
	pair<int, int> add = {-1, -1};
	bool check = false;
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j)
			if(a[i][j] >= 2){
				add = {i, j};
				check = true;
				break;
			}
		if(check) break;
	}
	if(check)	cout << add.first << " " << add.second;
	else cout << "Khong tim thay";
}
void peak(){
	for(int i=0; i<n; ++i){
		int sum = 0;
		for(int j=0; j<n; ++j){
			if(i==j)	sum += 2*a[i][j];
			else sum += a[i][j];
		}
		degree[i] = sum;
	}
	for(int i=0; i<n; ++i){
		if(degree[i] == 1)
			treo.push_back(i);
		if(degree[i] == 0)
			co.push_back(i);
	}
}
void solve(){
	faster
	file("TASK");
    input();
    cout << "Cap canh song song :\n";
    edge();
    peak();
    cout << "\nDinh treo\n";
    for(int x : treo)
    	cout << x << " ";
    cout << "\nDinh co lap\n";
    for(int x : co)
    	cout << x << " ";
}
signed main(){
    solve();
    print_time();
}
