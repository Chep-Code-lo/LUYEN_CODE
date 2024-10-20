#include<iostream>
using namespace std;
int n, maxx, a[1003];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], maxx = max(maxx, a[i]);
    for(int i=0; i<n; ++i)
        if(a[i] == maxx){
            cout << maxx << " " << i+1;
            break;
        }
}