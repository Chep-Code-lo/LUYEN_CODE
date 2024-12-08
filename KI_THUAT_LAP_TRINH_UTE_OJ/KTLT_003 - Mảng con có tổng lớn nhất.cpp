#include<iostream>
using namespace std;
int n;
long long a[200005];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i];
    long long current_sum = a[0];
    long long max_sum = a[0];
    for(int i=1; i<n; ++i){
        current_sum = max(a[i], a[i]+current_sum);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}