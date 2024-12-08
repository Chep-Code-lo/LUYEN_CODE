#include<iostream>
#include<algorithm>
using namespace std;
int n, a[100005], b[100005];
long long product;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i];
    for(int i=0; i<n; ++i)  cin >> b[i];
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    for(int i=0; i<n; ++i)
        product += a[i]*b[i];
    cout << product;
}