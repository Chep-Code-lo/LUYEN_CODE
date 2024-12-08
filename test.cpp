#include<iostream>
#include<math.h>
using namespace std;
long long n, a[100000];
long long current_sum, max_sum;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i){
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }
}