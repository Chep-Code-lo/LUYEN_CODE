#include<iostream>
using namespace std;
int n, a[1000006];
int main(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=n; i>=1; --i)
        if(i%2 != 0)
            cout << a[i] << " ";
}