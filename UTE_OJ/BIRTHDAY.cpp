#include<iostream>
using namespace std;
int n, minn = 1e9, a[10000], b[10000];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)  cin >> b[i];
    for(int i=0; i<n; ++i)
        minn = min(minn, b[i]/a[i]);
    cout << minn;
}