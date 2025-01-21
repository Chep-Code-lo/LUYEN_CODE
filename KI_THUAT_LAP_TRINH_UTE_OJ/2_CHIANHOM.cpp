//Author: Chép Code lỏ
//Github: @Chep-Code-lo
#include<bits/stdc++.h>
using namespace std;
int n, total_sum, a[21], minn = 1e6;
void input(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i], total_sum += a[i];
}
void backtrack(int i, int current_sum){
    if(i == n){
        int temp = total_sum - current_sum;
        minn = min(minn, abs(temp - current_sum));
        return;
    }
    backtrack(i+1, current_sum + a[i]);
    backtrack(i+1, current_sum);
}
void dp_knapsack(){
    int m = total_sum / 2;
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for(int i=0; i<n; ++i)
        for(int j=m; j>=a[i]; --j)
            dp[j] = dp[j] || dp[j-a[i]];
    int temp = 0;
    for(int j=m; j>=0; --j){
        if(dp[j]){
            temp = j;
            break;
        }
    }
    cout << total_sum -2*temp;
}
int main(){
    input();
    backtrack(0, 0);
    //cout << minn;
    dp_knapsack();
}