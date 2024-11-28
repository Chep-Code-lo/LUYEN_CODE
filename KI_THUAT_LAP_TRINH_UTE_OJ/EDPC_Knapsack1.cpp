#include <iostream>
#include <algorithm>
using namespace std;
int n, m, w, v;
long long f[1000005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> w >> v;
        for(int j=m; j>=w; j--) f[j] = max(f[j], f[j-w] + v);
    }
    cout << f[m];
}
    