// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5;
int n, k, a[N], b[N], maxx=-1e9;
int main(){
    faster
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(a[i] > maxx)  b[i] = a[i], maxx = a[i];
        else b[i] = maxx;
    }
    //for(int i=0; i<n; ++i)  cout << b[i] << " ";  
    while(k--){
        int x; cin>> x;
        cout << b[x-1] << "\n";
    }
}