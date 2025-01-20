// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#include<iostream>
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5+5;
const int MOD = 1e9+7;
long long a[N][3];
int n;
int main(){
    cin >> n;
    //a[i][1] ko chọn 1 (0, 2)
    //a[i][2] chọn 1 (1)
    a[1][1]=2, a[1][2] = 1;
    for(int i=2; i<=n; ++i){
        a[i][1] = a[i-1][1]*2 + a[i-1][2]*2;
        a[i][2] = a[i-1][1];
        a[i][1] %= MOD;
        a[i][2] %= MOD;
    }
    cout << (a[n][1] + a[n][2])%MOD;
}