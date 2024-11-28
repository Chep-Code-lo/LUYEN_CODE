#include<iostream>
using namespace std;
int n, pos, minn = 1e9, a[101];
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(is_prime(a[i])) minn = min(minn, a[i]);
    } 
    for(int i=0; i<n; ++i)
        if(minn == a[i]){
            pos = i;
            break;
        }
    if(minn == 1e9) cout << -1;
    else cout << pos;
}