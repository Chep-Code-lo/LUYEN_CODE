#include <iostream>
using namespace std;
int n, a[101], pre[101], f[101][101];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i]; 
    }
    auto sum = [&](int l, int r) {return pre[r] - pre[l-1];};
    for(int i=0; i<n; ++i)  f[i][i] = a[i];
    for(int i=2; i<=n; ++i)
        for(int l=1; l+i-1<=n; ++l){
            int r = i+l-1;
            int A = a[l] + (sum(l+1, r) - f[l+1][r]);
            int B = a[r] + (sum(l, r-1) - f[l][r-1]);
            f[l][r] = max(A, B);
        }
    cout << f[1][n];
}