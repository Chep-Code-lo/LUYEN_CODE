#include<iostream>
using namespace std;
int n, k, a[1003];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    k = k%n;
    for(int i=1+k; i<=n; ++i)
        cout << a[i] << " ";
    for(int i=1; i<=k; ++i)
        cout << a[i] << " ";
}