#include<iostream>
#define N int(2e5+1)
using namespace std;
int t, n, f[N], s[N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; ++i) cin >> s[i];
        for(int i=0; i<n; ++i) cin >> f[i];
        for(int i=0; i<n; ++i)
            cout << f[i] - max(f[i-1], s[i]) << " \n"[i == n-1];
    }
}