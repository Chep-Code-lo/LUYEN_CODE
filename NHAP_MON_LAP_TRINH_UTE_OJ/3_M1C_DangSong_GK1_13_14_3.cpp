#include<iostream>
using namespace std;
int n, a[50];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=1; i<n-1; ++i)
        if(!((a[i-1]<a[i] && a[i]>a[i+1]) || (a[i-1]>a[i] && a[i]<a[i+1]))){
            cout << i;
            return 0;
        }
    cout << -1;      
}
