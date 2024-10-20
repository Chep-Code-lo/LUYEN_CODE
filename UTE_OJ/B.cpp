#include<iostream>
using namespace std;
int n, minn = 1e7, a[1005];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], minn = min(minn, a[i]);
    cout << minn << "\n";
}