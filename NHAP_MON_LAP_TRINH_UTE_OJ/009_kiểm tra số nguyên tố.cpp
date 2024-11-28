#include<bits/stdc++.h>
#define file(name)  freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define int long long
using namespace std;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6) 
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int n;
signed main(){
    //file("ckprime1")
    cin >> n;
    cout << (is_prime(n) ? "YES" : "NO");
}