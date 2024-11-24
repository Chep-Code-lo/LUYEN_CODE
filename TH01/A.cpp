#include<iostream>
using namespace std;
int a, n, cnt;
float res, result, X;
int main(){
    cin >> a >> n >> X;
    float x = 0.01*X;
    float ans = n - a*x;
    //cout << ans;
    res = a - ans;
    result = res + ans;
    while(result > n){
        ans = n - res*x;
        res = res - ans;
        result = res + ans;
        cnt++;
    } 
    cout << cnt+1;
}