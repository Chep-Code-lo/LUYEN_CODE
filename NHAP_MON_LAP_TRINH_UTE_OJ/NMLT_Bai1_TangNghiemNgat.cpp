#include<iostream>
using namespace std;
int n, pos, a[202];
bool check;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i)
        if(a[i-1] >= a[i]){
            pos = i;
            break;
        }
    if(pos > 0) cout << pos;
    else cout << -1;
}