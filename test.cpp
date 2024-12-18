#include<bits/stdc++.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int n, x, t=1;
long long s;
int main(){
    cin >> n >> x;
    for(int i=1; i<=n; ++i){
        t = pow(x, 2*i - 1);
        s += t;
    }
    cout << s;
}