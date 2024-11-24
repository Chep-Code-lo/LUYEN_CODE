#include<iostream>
using namespace std;
int n, a[1000006];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if(a[i] < 0) cout << a[i] << " ";
    for(int i=0; i<n; ++i)
        if(a[i] > 0) cout << a[i] << " ";
}