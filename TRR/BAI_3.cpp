#include <iostream>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e6+1;
int n, k, best_sum, a[N];
vector<int>add_sum;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> k;
	for(int i=0; i<n; ++i)	cin >> a[i];
}
void backtrack(int index, vector<int>&temp_sum, int current_sum){
	if(current_sum >= k)	return;
	if(current_sum > best_sum){
		best_sum = current_sum;
		add_sum = temp_sum;
	}
	for(int i=index; i<n; ++i){
		temp_sum.push_back(a[i]);
		backtrack(i+1, temp_sum, current_sum + a[i]);
		temp_sum.pop_back();
	}
}
void solve(){
	faster
	//file("");
    input();
    vector<int>temp_sum;
    backtrack(0, temp_sum, 0);
    for(int x : add_sum)	cout << x << " ";
}
signed main(){
    solve();
    time();
}
