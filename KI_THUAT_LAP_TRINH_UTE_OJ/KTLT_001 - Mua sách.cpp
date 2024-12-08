#include<iostream>
#include<algorithm>
#define N int(1e5)
using namespace std;
int n, a[N];
long long ans;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i], ans += a[i];
    sort(a, a+n, greater<int>());
    for(int i=2; i<n; i+=3) ans -= a[i];
    cout << ans;
}
/*10 9 8 7 6 5 4 3 2 1
       *     *     *   */