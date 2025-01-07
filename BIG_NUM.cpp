// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define ll int
#define ft first
#define sd second
//#define endl '\n'
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define no cout<<"NO"<<'\n'
#define no_ cout<<"No"<<'\n'
#define _no cout<<"no"<<'\n'
#define lowbit(a) ((a)&-(a))
#define yes cout<<"YES"<<'\n'
#define yes_ cout<<"Yes"<<'\n'
#define _yes cout<<"yes"<<'\n'
#define ull unsigned long long
#define all(x) x.begin(),x.end()
#define nps fixed<<setprecision(10)<<
#define mem(a,k) memset(a,k,sizeof(a))
#define debug(x) cout<<#x<<"="<<x<<endl
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define N int(1e7)
#define M int(3e6+3)
#define X int(1e6)
#define MAX int(1e12)
#define bigInt vector<int>
const ll mod1=1e9+7;
const ll mod2=998244353;
const ll base=1610612741;
const ll INF=0x3f3f3f3f3f;
const ll inf=9223372036854775807;
const ll Z=mod2;
const ll mod=Z;
const int BASE = 1000;
const int LENGTH = 3;
using namespace std;
int ddir[2][2]={{0,1},{1,0}};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
struct custom_hash
{
    static ull splitmix64(ull x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(ull x)const{static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}
    //unordered_map<ll,ll,custom_hash>mp;
};
struct mint
{
    ll x;
    mint(ll y = 0){if(y < 0 || y >= mod) y = (y%mod+mod)%mod; x = y;}
    mint(const mint &ope) {x = ope.x;}
    mint operator-(){return mint(-x);}
    mint operator+(const mint &ope){return mint(x) += ope;}
    mint operator-(const mint &ope){return mint(x) -= ope;}
    mint operator*(const mint &ope){return mint(x) *= ope;}
    mint operator/(const mint &ope){return mint(x) /= ope;}
    mint& operator+=(const mint &ope){x += ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator-=(const mint &ope){x += mod - ope.x; if(x >= mod) x -= mod; return *this;}
    mint& operator*=(const mint &ope){ll tmp = x; tmp *= ope.x, tmp %= mod; x = tmp; return *this;}
    mint& operator/=(const mint &ope){ll n = mod-2; mint mul = ope;while(n){if(n & 1) *this *= mul; mul *= mul; n >>= 1;}return *this;}
    mint inverse(){return mint(1) / *this;}
    bool operator ==(const mint &ope){return x == ope.x;}
    bool operator !=(const mint &ope){return x != ope.x;}
    bool operator <(const mint &ope)const{return x < ope.x;}
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
ll rnd(ll l,ll r){ll ans=uniform_int_distribution<ll>(l,r)(rng);return ans;}
ll qpow(ll a,ll b){ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
ll qpow(ll a,ll b,ll m){a%=m;ll res=1;while(b>0){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}
double psqrt(double x,double y,double xx,double yy){double res=((x-xx)*(x-xx)+(y-yy)*(y-yy));return res;}
double ssqrt(double x,double y,double xx,double yy){double res=sqrt(psqrt(x,y,xx,yy));return res;}
ll INV(ll x){return qpow(x,Z-2,Z);}
void cominit(ll fac[],ll inv[]){fac[0]=1;rep(i,1,1000000)fac[i]=fac[i-1]*i%Z;
inv[1000000]=INV(fac[1000000]);per(i,1000000-1,0)inv[i]=inv[i+1]*(i+1)%Z;}
bigInt& fix(bigInt &a){
  a.push_back(0);
  for (int i = 0; i + 1 < a.size(); ++i){
    a[i + 1] += a[i] / BASE; a[i] %= BASE;
    if (a[i] < 0) a[i] += BASE, --a[i + 1];
  }
  while (a.size() > 1 && a.back() == 0) a.pop_back();
  return a;
}
bigInt big(int x){
  bigInt result;
  while (x > 0) {
    result.push_back(x % BASE);
    x /= BASE;
  }
  return result;
}
bigInt big(string s){
  bigInt result(s.size() / LENGTH + 1);
  for (int i = 0; i < s.size(); ++i) {
    int pos = (s.size() - i - 1) / LENGTH;
    result[pos] = result[pos] * 10 + s[i] - '0';
  }
  return fix(result), result;
}
int compare(bigInt &a, bigInt &b){
  if (a.size() != b.size()) return (int)a.size() - (int)b.size();
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) return a[i] - b[i];
  return 0;
}
#define DEFINE_OPERATOR(x) bool operator x (bigInt &a, bigInt &b) { return compare(a, b) x 0; }
DEFINE_OPERATOR(==)
DEFINE_OPERATOR(!=)
DEFINE_OPERATOR(>)
DEFINE_OPERATOR(<)
DEFINE_OPERATOR(>=)
DEFINE_OPERATOR(<=)
#undef DEFINE_OPERATOR
void operator += (bigInt &a, bigInt b){
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < b.size(); ++i)
    a[i] += b[i];
  fix(a);
}
void operator -= (bigInt &a, bigInt b){
  for (int i = 0; i < b.size(); ++i)
    a[i] -= b[i];
  fix(a);
}
void operator *= (bigInt &a, int b){
  for (int i = 0; i < a.size(); ++i)
    a[i] *= b;
  fix(a);
}
void divide(bigInt a, int b, bigInt &q, int &r){
  for (int i = int(a.size()) - 1; i >= 0; --i) {
    r = r * BASE + a[i];
    q.push_back(r / b); r %= b;
  }
  reverse(q.begin(), q.end());
  fix(q);
}
bigInt operator + (bigInt a, bigInt b) { a += b; return a; }
bigInt operator - (bigInt a, bigInt b) { a -= b; return a; }
bigInt operator * (bigInt a, int b) { a *= b; return a; }
bigInt operator / (bigInt a, int b){
  bigInt q; int r = 0;
  divide(a, b, q, r);
  return q;
}
int operator % (bigInt a, long b){
  bigInt q; int r = 0;
  divide(a, b, q, r);
  return r;
}
bigInt operator * (bigInt a, bigInt b){
  bigInt result (a.size() + b.size());
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b.size(); ++j)
      result[i + j] += a[i] * b[j];
  return fix(result);
}
istream& operator >> (istream& cin, bigInt &a){
  string s; cin >> s;
  a = big(s);
  return cin;
}
ostream& operator << (ostream& cout, const bigInt &a){
  cout << a.back();
  for (int i = (int)a.size() - 2; i >= 0; --i)
    cout << setw(LENGTH) << setfill('0') << a[i];
  return cout;
}
