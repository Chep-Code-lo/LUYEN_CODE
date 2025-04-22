#include <iostream>
#include <vector>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, a[20];
vector<int>best_list, temp_list;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=0; i<n; ++i)	cin >> a[i];
}
void backtrack(int index){
	if(temp_list.size() > best_list.size())
		best_list = temp_list;
	for(int i=index; i<n; ++i){
		if(temp_list.empty() || a[i] > temp_list.back()){
			temp_list.push_back(a[i]);
			backtrack(i+1);
			temp_list.pop_back();
		}
	}
}s
void solve(){
	faster
	//file("");
    input();
    backtrack(0);
    for(int x : best_list)	cout << x << " ";
}
signed main(){
    solve();
    time();
}
