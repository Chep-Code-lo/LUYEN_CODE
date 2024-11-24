#include<iostream>
using namespace std;
int n, count, x = 1, a[1003], b[1003];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=n; i>=1; --i)
        b[x++] = a[i]; 
    for(int i=1; i<=n; ++i)
        if(a[i] != b[i]){
            count++;
            break;
        } 
    cout << (count == 0 ? "YES" : "NO");
}