#include<iostream>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, n, a[50];
int main(){
    faster
    cin >> t;
    while (t--)
    {
        bool ok = true;
        cin >> n;
        for(int i=0; i<n; ++i) cin >> a[i];
        for(int i=1; i<n; ++i){
            int x = abs(a[i] - a[i-1]);
            if(x != 5 && x != 7){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
}