#include<iostream>
#include<math.h>
using namespace std;
int n, minn = 1e9;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int l, r, cnt;
int main(){
    cin >> l >> r;
    for(int i=sqrt(l)+1; i<=sqrt(r); ++i)
        if(is_prime(i))
            cnt++;
    cout << cnt;
}