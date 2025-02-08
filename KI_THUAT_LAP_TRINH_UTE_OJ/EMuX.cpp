// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<bits/stdc++.h>
using namespace std;
long long fac(int x){
    long long res = 1;
    for(int i=1; i<=x; ++i)
        res *= i;
    return res;
}
double Sum(double x, int n){
    double S = 1.0;
    double term = 1.0;
    for(int i=1; i<=n; ++i){
        term *= x / i;
        S += term;
    }
    return S;
}
int main(){
    double res = 1;
    double x, n; cin >> x >> n;
    for(int i=1; i<=n; ++i){
        res = res + (pow(x, i) / fac(i));
    }
    double ans = Sum(x, n);
    cout << fixed << setprecision(2) << ans;
}