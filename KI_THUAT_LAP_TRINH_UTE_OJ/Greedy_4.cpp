#include <iostream>
#include <string>
#include <vector>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m;
vector<string>s, current_s;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n >> m;
	s.resize(n); current_s.resize(m);
	for(int i=0; i<n; ++i)	cin >> s[i];
	for(int i=0; i<m; ++i)	cin >> current_s[i];
}
void solve(){
	faster
	//file("");
    input();
    int l=0, r=0;
    while(l < n && r < m){
    	if(s[l] == current_s[r]) r++;
    	l++;
    }
    cout << (r == m ? "YES" : "NO");
}
signed main(){
    solve();
    time();
}
