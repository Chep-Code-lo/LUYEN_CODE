//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
using namespace std;
int f(long long x){
    if(x==0) return 1;
    return (f(x/2) + f(x/3));
}
long long x;
int main(){
    cin >> x;
    cout << f(x);
}