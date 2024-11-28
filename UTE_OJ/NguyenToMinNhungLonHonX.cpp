#include<iostream>
using namespace std;
int n, k, minn = 1e9;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int main(){
    cin >> n >> k;
    for(int x, i=0; i<n; ++i){
        cin >> x;
        if(is_prime(x) && x > k) minn = min(minn, x);
    } 
    if(minn == 1e9) cout << 0;
    else cout << minn;
}