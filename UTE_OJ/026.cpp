#include<iostream>
using namespace std;
int n, maxx, a[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n-1; ++i)  maxx = max(maxx, abs(a[i+1] - a[i]));
    cout << maxx << "\n";
}