#include<iostream>
#define N int(1e3 + 3)
using namespace std;

int n, m, a[N][N], dp[N][N];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            cin >> a[i][j];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            dp[i][0] = -1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            dp[0][j] = -1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){
            if(i==1 && j==1) dp[i][j] = a[i][j];
            else if(a[i][j] != -1 && (dp[i][j-1] != -1 || dp[i-1][j] != -1))
                dp[i][j] = max(a[i][j] + dp[i][j-1], a[i][j] + dp[i-1][j]);
            else 
                dp[i][j] = -1;
        }
    cout << dp[n][m] << "\n";
}