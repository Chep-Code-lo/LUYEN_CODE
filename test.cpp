#include<iostream>
#include<vector>
#include<algorithm>
#define naxi(x, y, z) nax(x, nax(y, z))
using namespace std;
int n;
long long res = -1e10, f[1005][1005], a[1005][1005], trace[1005][1005];
int main() {
    cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) cin >> a[i][j];
    for(int i=0; i<=n; ++i) f[0][i] = f[n+1][i] = -1e15;
    for(int j=1; j<=n; ++j){
        for(int i=1; i<=n; ++i){
            if(f[i-1][j-1] >= f[i][j-1] && f[i-1][j-1] >= f[i+1][j-1]){
                f[i][j] = f[i-1][j-1] + a[i][j];
                trace[i][j] = i-1;
            }else if (f[i][j-1] >= f[i+1][j-1]){
                f[i][j] = f[i][j-1] + a[i][j];
                trace[i][j] = i;
            }else{
                f[i][j] = f[i+1][j-1] + a[i][j];
                trace[i][j] = i+1;
            }
        }
    }
    int best_row = 1;
    for(int i=1; i<=n; ++i){
        if(f[i][n] > res){
            res = f[i][n];
            best_row = i;
        }
    }
    vector<int>ans;
    int current_row = best_row;
    for(int j=n; j>=1; j--){
        ans.push_back(a[current_row][j]);
        current_row = trace[current_row][j];
    }
    reverse(ans.begin(), ans.end());
    cout << res << "\n";
    //for(int x : ans)   cout << x << " ";
}
