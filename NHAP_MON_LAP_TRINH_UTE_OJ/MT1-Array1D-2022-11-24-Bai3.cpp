#include<iostream>
#include<algorithm>
using namespace std;
int n, max_1, max_2, a[103];
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i=1; i<n; ++i)
        if(a[0] != a[i]){
            max_1 = a[0]*a[i];
            break;
        }
    for(int i=n-2; i>=0; --i)
        if(a[n-1] != a[i]){
            max_2 = a[n-1]*a[i];
            break;
        }
    cout << max(max_1, max_2);
}