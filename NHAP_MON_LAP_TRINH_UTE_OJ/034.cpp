#include<iostream>
#include<algorithm>
using namespace std;
int n, x, y, a[1003];
long long sum, ans, res;
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
    cin >> x >> y;
    for(int i=x; i!= y; i=(i%n) + 1)   ans += a[i];
    res = sum - ans;
    cout << min(res, ans);
}   
