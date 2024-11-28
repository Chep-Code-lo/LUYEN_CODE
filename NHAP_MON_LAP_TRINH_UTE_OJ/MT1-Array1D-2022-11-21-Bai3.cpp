#include<iostream>
using namespace std;
int n, x, pos, res, minn = INT_MAX, a[103];
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i)
        if (a[i] != x){
            res = abs(x - a[i]);
            if (res < minn){
                minn = res;
                pos = i;
            }
        }
    cout << pos;
}