#include <iostream>
#include <string>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
string s;
const string cur = "aieouAIEOU";
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> s;
}
void solve(){
	faster
	//file("");
    input();
    s.erase(remove_if(s.begin(), s.end(), [&](char c){
    	return cur.find(c) != string :: npos;
    }), s.end());
    cout << s;
}
signed main(){
    solve();
    print_time();
}
