#include<iostream>
#include<algorithm>
using namespace std;
int n, a[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i=n-2; i>=0; --i)
        if(a[n-1] != a[i]){
            cout << a[i];
            break;
        }
}