#include<iostream>
using namespace std;
int n, k, a[1003];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if(a[i] == k){
            cout << "YES";
            return 0;
        }
    cout << "NO";
}