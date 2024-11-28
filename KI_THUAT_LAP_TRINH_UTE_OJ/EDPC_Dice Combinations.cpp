#include<iostream>
#define N int(1e6+5)
#define MOD int(1e9+7)
#define faster cin.tie(0)->sync_with_stdio(0);
using namespace std;
long long f[N]{0};
int n;
int main(){
    cin >> n;
    for(int i=0; i<=6; ++i) f[i]=1;
    for(int i=2; i<=n; ++i)
        for(int j=min(6,i-1); j>=1; --j)
            f[i] = (f[i] + f[i-j]) % MOD;
    cout << f[n] << "\n";
}
