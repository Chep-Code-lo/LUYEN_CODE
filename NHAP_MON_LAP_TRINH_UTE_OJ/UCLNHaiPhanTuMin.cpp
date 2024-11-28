#include<iostream>
#include<algorithm>
using namespace std;
int n, a[10004];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    cout << __gcd(a[0], a[1]);
}