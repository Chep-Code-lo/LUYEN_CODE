#include <iostream>
#include <iomanip>
#include <format>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n;
}
string center(string s, int w){
    if(w <= s.size()) return s;
    int left = (w - s.size())/2;
    int right = w - s.size() - left;
    return string(left, ' ') + s + string(right, ' ');
}
void solve(){
    faster
    file("Chan_tri");
    //input();
    cout << left << setw(3) << "p" 
         << left << setw(3) << "q" 
         << left << setw(3) << "r"
         << setw(4) << center("p^q", 4)
         << setw(7) << center("(p^q)->r", 7) << "\n";
    for(bool p : {true, false})
        for(bool q : {true, false})
            for(bool r : {true, false}){
                bool pq = p&&q;
                bool temp = (!p^q)||r;
                cout << left << setw(3) << (p ? "1" : "0")
                     << left << setw(3) << (q ? "1" : "0")
                     << left << setw(3) << (r ? "1" : "0")
                     << setw(4) << center(pq ? "1" : "0", 4)
                     << setw(7) << center(temp ? "1" : "0", 7) << "\n";
            }
}
signed main(){
    solve();
    print_time();
}
