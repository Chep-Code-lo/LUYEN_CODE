#include<iostream>
using namespace std;
int n, k, pos=-1e9;
int main(){
    cin >> n >> k;
    for(int x, i=0; i<n; ++i){
        cin >> x;
        if(x == k)  pos = i;
    }
    if(pos == -1e9) cout << -1;
    else cout << pos;
}