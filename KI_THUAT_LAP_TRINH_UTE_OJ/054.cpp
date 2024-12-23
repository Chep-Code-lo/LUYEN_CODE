#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define N int(1e7)
#define M int(3e6+3)
#define X int(1e6)
#define MAX int(1e12)
using namespace std;
ld Bin_Pow(ld a, ll b){
    ld res = 1.0;
    while(b > 0){
        if(b & 1)// kiểm tra bit cuối bằng 1 không (tức b lẻ)
            res *= a;
        a*=a;
        b >>= 1;// Dịch b một bit sang phải (tức chia b cho 2)
    }
    return res;
}
ld Cube_root(const string &x){
    ld num = stold(x);
    ld l=0, r=num, mid;
    if(num < 1) r=1;
    while(r-l > 1e-11){
        mid = (l+r)/2;
        if(Bin_Pow(mid, 3) <= num)  l=mid;
        else r=mid;
    }
    return l;
}
string s;
int main(){
    faster
    cin >> s;
    ld res = Cube_root(s);
    cout << fixed << setprecision(10) << res;
}
