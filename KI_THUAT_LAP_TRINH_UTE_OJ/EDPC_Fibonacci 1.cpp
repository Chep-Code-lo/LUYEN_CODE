#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define int long long
using namespace std;
int MOD = 1e9 + 7, N = 1e6;
int n, f[1000000+1];
signed main(){
    int n; cin >> n;
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; ++i)
        f[i] = ((f[i-1] + f[i-2]) % MOD);
    cout << f[n];
}
