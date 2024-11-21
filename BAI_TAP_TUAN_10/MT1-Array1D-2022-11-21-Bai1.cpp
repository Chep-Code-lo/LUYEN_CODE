#include<iostream>
using namespace std;
int n, maxx = -1e9, pos_1, pos_2, a[103];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], maxx = max(maxx, a[i]);
    for(int i=0; i<n; ++i)
        if(a[i] == maxx){
            pos_1 = i;
            break;
        }
    for(int i=n-1; i>=0; --i)
        if(a[i] == maxx){
            pos_2 = i;
            break;
        }
    cout << pos_2 - pos_1;
}