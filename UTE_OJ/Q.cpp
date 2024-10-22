#include<iostream>
#include<algorithm>
using namespace std;
int n, countt, a[1003], b[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i=0; i<n; ++i)
        if(a[i] != b[i]){
            countt++;
            break;
        }
    cout << (countt == 0 ? "YES" : "NO");
}