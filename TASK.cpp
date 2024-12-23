#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int n, m, maxx = -1e10, cnt, a[1003][1003];
long long x;
signed main(){
    file_chuan("TASK");
    cin >> x;
    x = abs(x);
    if(x == 1){
        cout << 2;
        return 0;
    }
    else
        cout << (x+2)/3;
}