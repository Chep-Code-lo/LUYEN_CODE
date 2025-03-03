#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXZ = 1e6 + 1;
bitset <MAXZ> sdb;
vector <ll> ttt_num;
void xuly(){
    sdb.reset();
    ttt_num.resize(MAXZ,0);
    for (int i=9;i<MAXZ;i+=3){
        int d = 2;
        for (int j=2;j<=sqrt(i);j++)
            if (i%j==0) 
                d += (j==i/j)? 1 : 2;
        if (d==9) sdb.set(i);
    }
    for(int i=1;i<MAXZ;i++) ttt_num[i] = ttt_num[i-1] + sdb[i];

}
ll demsdb(ll a, ll b){
    while (a%3!=0 && a<=b) a ++;
    return ttt_num[b] - ttt_num[a-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    xuly();
    while (t--){
        ll a, b; cin >> a >> b;
        cout << demsdb(a,b) << "\n";
    }
    return 0;
}