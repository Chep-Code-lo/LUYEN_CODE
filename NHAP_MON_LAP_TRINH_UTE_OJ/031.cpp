#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n, a[1003];
signed main(){
    cin >> n;
    for(int i=0; i<=n; ++i) cin >> a[i];
    sort(a, a+n);
    cout << max(a[0]*a[1], a[n-1]*a[n-2]);
}
