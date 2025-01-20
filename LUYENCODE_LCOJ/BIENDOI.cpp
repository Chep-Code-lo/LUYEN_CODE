// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5+5;
int t, a[N];
void solve(){
    for(int i=2; i<=100001; ++i){
        a[i] = a[i-1] + 1;
        if(i%2 == 0)    a[i] = min(a[i], a[i/2] + 1);
        if(i%3 == 0)    a[i] = min(a[i], a[i/3] + 1);
    }
}
int main(){
    faster
    solve();
    cin >> t;
    while (t--){
        int x; cin >> x;
        cout << a[x] << "\n";
    }
}