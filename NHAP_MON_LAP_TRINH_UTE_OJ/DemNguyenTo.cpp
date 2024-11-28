#include<iostream>
using namespace std;
int n, cnt, a[103];
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
    for(int x, i=0; i<n; ++i) cin >> x, cnt += (is_prime(x)) ? 1 : 0;
    cout << cnt;
}