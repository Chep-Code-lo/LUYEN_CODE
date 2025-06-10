//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <bits/stdc++.h>
#define ll long long
template  <typename T> bool maximize(T &a, const T b) { if(a < b) { a = b; return true; } return false; }
template  <typename T> bool minimize(T &a, const T b) { if(a > b) { a = b; return true; } return false; }
inline int readInt()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();int n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline ll readLong()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline string readString() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}
inline bool getbit(int n, int i) { return n >> i & 1; }
inline int  offbit(int n, int i) { if(getbit(n, i)) n &= (1 << i); return n; }
inline int   onbit(int n, int i) { n |= (1 << i); return n; }
inline int    flip(int n, int i) { return n ^ (1 << i); }
const int  MOD = 998244353;
const  ll  LIM = 2e5 + 10;
const int    N = 4e5 + 4;
const int  INF = 0x3f3f3f3f;
const  ll LINF = (ll)1e18 + 100;
const int  LOG = 50;
const ll  base = 4e4 + 5;
const int offset = 6e3 + 101;
const int dx[] = { -2, -2, -1, 1, 2, +2, +1, -1 };
const int dy[] = { -1, +1, +2, 2, 1, -1, -2, -2 };
const int block_size = 316;
const char eval[] = { 'D', 'X', 'L', 'V' };
const pii pivot = make_pair(5, 5);
//const pii pivot = make_pair(10, 10);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int mul(int a, int b) { return 1LL * a * b % MOD; }
inline int sub(int a, int b) { a -= b; if(a < 0) a += MOD; return a; }
inline int add(int a, int b) { a += b; if(a >= MOD) a -= MOD; return a; }
inline void ADD(int &a, int b) { a += b; if(a >= MOD) a -= MOD; if(a < 0) a += MOD; }
inline void SUB(int &a, int b) { a -= b; if(a < 0) a += MOD; }
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
}
void solve(){
    faster
    file("TASK");
    input();
}
signed main(){
    solve();
    print_time();
}