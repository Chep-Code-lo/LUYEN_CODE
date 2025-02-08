// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int dir1[2][2]={{0,1},{1,0}};
int dir2[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
int n, k, max_sum = -1e6, total_sum, a[25];
void input(){
    file("TASK");
    cin >> n >> k;
    for(int i=0; i<n; ++i)  cin >> a[i];
}
void backtrack(int i, int current_sum){
    if(i == n){
        if(current_sum % k == 0)    max_sum = max(max_sum, current_sum);
        return;
    }
    backtrack(i+1, current_sum + a[i]);
    backtrack(i+1, current_sum);
}
void dp(){
    vector<int> dp(k, -1);
    dp[0] = 0;
    for(int i=0; i<n; ++i){
        vector<int> temp(dp);
        for(int r = 0; r < k; r++)
            if(dp[r] != -1){
                int newR = (r + a[i]) % k;
                temp[newR] = max(temp[newR], dp[r] + a[i]);
            }
        dp = temp;
    }
    cout << dp[0];
}
int main(){
    input();
    backtrack(0, 0);
    //cout << max_sum;
    dp();
    time();
}
/*5 7
33 54 51 48 15*/