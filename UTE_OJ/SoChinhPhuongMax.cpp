#include<iostream>
#include<math.h>
using namespace std;
int n, maxx = -1e9;
bool Square_Number(long long x){
    int res = sqrt(x);
    return(1ll*res*res == x);
}
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i) cin >> x , maxx = max(maxx, Square_Number(x) ? x : -1);
    cout << maxx;
}