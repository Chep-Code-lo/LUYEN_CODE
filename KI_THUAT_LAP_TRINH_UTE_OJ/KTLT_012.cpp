//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
using namespace std;
int n, ans, w[12];
void backtracking(int pos, int l, int r){
    if(pos == n){
        if(l == r) ans = max(ans, l+r);
        return;
    }
    backtracking(pos+1, l, r);
    backtracking(pos+1, l+w[pos], r);
    backtracking(pos+1, l, r+w[pos]);
}
int main(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> w[i];
    backtracking(0, 0, 0);
    cout << ans;
}
/*5
1 1 1 1 1*/