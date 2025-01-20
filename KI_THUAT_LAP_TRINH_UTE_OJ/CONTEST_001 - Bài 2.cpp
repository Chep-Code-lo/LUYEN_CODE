#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e6;
int n, ans = 1, a[200005],prime[M+1];
vector<int>dp(M, 1e9),trace, add, lis, pos(M, -1);
void Eratosthenes_Sieve(){
    for(int i=1; i<=M; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(M); ++i)
        if(prime[i])
            for(int j=i*i; j<=M; j+=i)
                prime[j] = 0;
}
void input(){
    cin >> n;
    for(int x, i=0; i<n; ++i){
        cin >> x;
        if(prime[x]) add.push_back(x);
    } 
}
void input1(){
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i];
}
void solve(){
    dp[0] = -1e9;
    trace.assign(add.size(), -1);
    for(int i=0; i<add.size(); ++i){
        int k = lower_bound(dp.begin(), dp.end(), add[i]) - dp.begin();
        //cout << k << " ";
        dp[k] = add[i];
        pos[k] = i;
        if(k > 1) trace[i] = pos[k-1];
        ans = max(ans, k);
    }
    cout << ans << "\n";
}
void trace_index(){
    int cur = pos[ans];
    while(cur != -1){
        lis.push_back(cur);
        cur = trace[cur];
    }
    reverse(lis.begin(), lis.end());
    for(auto x : lis)   cout << x+1 << " ";
}
void trace_lis(){
    for(int i=1; i<=ans; ++i)   cout << dp[i] << " ";
}
int main(){
    //file_chuan("dplis2");
    faster
    Eratosthenes_Sieve();
    input();
    solve();
    trace_lis();
    //trce();
}
/*5
11 2 3 3 7*/