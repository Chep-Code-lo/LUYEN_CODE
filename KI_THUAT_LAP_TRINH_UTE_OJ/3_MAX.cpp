//Author: Chép Code lỏ
//Github: @Chep-Code-lo
#include<bits/stdc++.h>
using namespace std;
int l[21][21];
string a, b, lcs = "";
void input(){
    cin >> a >> b;
}
void dp_lcs(){
    int n = a.size(), m = b.size();
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){
            if(a[i-1] == b[j-1])    l[i][j] = l[i-1][j-1] + 1;
            else l[i][j] = max(l[i-1][j], l[i][j-1]); 
        }
    //cout << l[n][m];
}
void trace(){
    lcs = "";
    int i = a.size(), j = b.size();
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs += a[i-1];
            i--; j--;
        }
        else if(l[i-1][j] > l[i][j-1])  i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
}
void solve(){
    while(true){
        dp_lcs();
        trace();
        if(lcs.empty()){
            cout << -1;
            return;
        }
        if(lcs[0] != '0'){
            cout << lcs;
            return;
        }
        int index_a = a.find('0'), index_b = b.find('0');
        if(index_a != string::npos) a.erase(index_a, 1);
        if(index_b != string::npos) b.erase(index_b, 1);
    }
} 
int main(){
    input();
    solve();
}
/*19012304
34012*/