#include<iostream>
using namespace std;
int n, a[103];
long long sum1, sum2;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], sum1 += a[i];
    for(int i=0; i<n-1; ++i){
        sum2 += a[i];
        if(sum2 == (sum1 - sum2)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}