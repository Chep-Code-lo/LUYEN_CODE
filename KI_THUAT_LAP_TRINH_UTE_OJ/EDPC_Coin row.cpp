#include<iostream>
#define N int(2e5+5)
#define faster cin.tie(0)->sync_with_stdio(0);
using namespace std;

long long n, a[N], f[N];
int main(){
    faster
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    f[0] = 0;
    f[1] = a[1];
    f[2] = max(a[1], a[2]);
    for(int i=3; i<=n; ++i)
        f[i] = max(f[i-2] + a[i], f[i-1]);
    cout << f[n] << "\n";
}