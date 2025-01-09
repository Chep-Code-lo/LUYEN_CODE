#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
using namespace std;
const int N = 5*1e5;
int n, index, ans, a[N];
vector<int>dp(N, 1e9);
bool is_prime(int x){
    for(int i=2; i<=sqrt(x); ++i)
        if(x%i == 0) return false;
    return x > 1;
}
int main(){
  file_chuan("TASK")
    cin >> n;
    for(int x, i=1; i<=n; ++i){
        cin >> x;
        if(is_prime(x)) a[++index] = x;
    } 
    dp[0] = -1e9;
    for(int i=2; i<=index; ++i){
        int k = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[k] = a[i];
        ans = max(ans, k);
    }
    cout << ans << "\n";
}
/*5
11 2 3 4 7*/