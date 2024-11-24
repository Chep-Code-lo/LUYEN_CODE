#include<iostream>
using namespace std;
int n, x;
long long res;
int main(){
    cin >> n >> x;
    if(x <= n*4)
        res = x*6700;
    else{
        res = n*4*6700;
        x -= n*4;
        if(n*2 >= x)
            res = res + x*12900;
        else{
            res = res +n*2*12900;
            x -= n*2;
            res = res + x*14400;
        }
    }
    cout << res;
}