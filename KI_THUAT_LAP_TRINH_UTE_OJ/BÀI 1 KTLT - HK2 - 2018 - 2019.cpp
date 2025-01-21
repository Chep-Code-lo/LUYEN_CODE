#include<bits/stdc++.h>
using namespace std;
int n, k;
void input(){
    cin >> k;
}
long long f(long long m){
    if(m == 0) return 2;
    if(m == 1) return 4;
    if(m == 2) return 6;
    return (2*f(m-3) + 4*f(m-2) + 6*f(m-1));
}
void find_n(){
    while(true){
        long long x = f(n);
        if(x > k){
            cout<< n-1;
            return;
        };
        n++;
    }
}

int main(){
    input();
    find_n();
}