#include<iostream>
#include<vector>
#include <climits>
#define N int(1e5+5)
using namespace std;
int  n, m, w, v;
vector<long long>dp(N, INT_MAX);
int main(){
    cin >> n >> m;
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        cin >> w >> v;
        for(int j=100000; j>=v; --j)
            dp[j] = min(dp[j], dp[j-v] + w);
    }
    for(int i=100000; i>0; --i)
        if(dp[i] <= m){
            cout << i << "\n";
            return 0;
        }
}
