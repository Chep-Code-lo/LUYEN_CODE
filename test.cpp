#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[2000000], b[2000000];
long long d;
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<m; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    for(int i=0; i<n; ++i)
        d += max(abs(a[i] - b[0]), abs(a[i] - b[m - 1]));
    cout << d;
}