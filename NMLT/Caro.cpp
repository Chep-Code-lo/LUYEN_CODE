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
const ll mod1=1e9+7;
const ll mod2=998244353;
const ll base=1610612741;
const ll INF=0x3f3f3f3f3f;
const ll inf=9223372036854775807;
const ll Z=mod2;
const ll mod=Z;
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
int m, n, len;
long long dev, ucode;
vector<string>s(501);
int core(string s, char play){
    int score=0, count=0;
    for(char x : s){
        if(x == play)
            count++;
        else{
            if(count >= 4)
                score += (count - 3);
            count=0;
        }    
    }
    if(count >= 4)
        score += (count - 3);
    return score;
}
int main(){
    cin >> m >> n;
    for(int i=0; i<m; ++i)  cin >> s[i];
    for(int i=0; i<m; ++i){
        dev += core(s[i], 'X');
        ucode += core(s[i], 'O');
    }
    for(int j=0; j<n; ++j){
        string column;
        for(int i=0; i<m; ++i)
            column += s[i][j];
        dev += core(column, 'X');
        ucode += core(column, 'O');
    }
    cout << dev << " " << ucode;
}
/*8 10
----------
-X-O-O----
-XXXXXO---
-XOXOX----
-X-OOX----
-X--OX----
---XOOOOO-
----OO----*/