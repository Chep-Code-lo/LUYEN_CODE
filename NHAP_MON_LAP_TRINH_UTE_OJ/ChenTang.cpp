#include<iostream>
#include<algorithm>
using namespace std;
int n, x, a[202];
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i)  cin >> a[i];
    a[n] = x;
    sort(a, a+n+1);
    for(int i=0; i<=n; ++i) cout << a[i] << " ";
}