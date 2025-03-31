#include <iostream>
#include <unordered_map>
#include <string>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
string s;
unordered_map<char, int>add;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> s;
	string r1 ="QWERTYUIOP";
	for(char x : r1) add[x] = 1;
	string r2 = "ASDFGHJKL";
	for(char x : r2) add[x] = 2;
	string r3 = "ZXCVBNM";
	for(char x : r3) add[x] = 3;
}
void solve(){
	faster
	//file("");
    input();
    int cnt = 0, current_row = add[s[0]];
    for(int i=1; i<s.size(); ++i){
    	int next_row = add[s[i]];
    	if(current_row != next_row)
    		cnt++, current_row = next_row;
    }
    cout << cnt;
}
signed main(){
    solve();
    time();
}
