//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
using namespace std;
int n, m, dp[1000][1000], matrix[1000][1000];
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        string s; cin >> s;
        for(int j=0; j<m; ++j)
            if(s[j] == '*')
                matrix[i][j] = 1;
    }
    /*for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }*/
   dp[0][0] = matrix[0][0];
    for(int i=1; i<n; ++i) 
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    for(int j=1; j<m; ++j)
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    /*for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    for(int i=1; i<n; ++i)
        for(int j=1; j<m; ++j)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
    cout << dp[n-1][m-1];

}
/*4 4
*..*
.*..
..*.
*..*
*/