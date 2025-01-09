#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e6;
const int N = 5e5;
int n, m, a[N], b[N], dp[N], prime[M+10];
void Eratosthenes_Sieve(){
    for(int i=1; i<=M; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(M); ++i)
        if(prime[i])
            for(int j=i*i; j<=M; j+=i)
                prime[j] = 0;
}
int binary(int l, int r, int x){
    int res=0;
    while(l <= r){
        int mid=(l+r)/2;
        if(a[b[mid]] <= x) res=mid, l=mid+1;
        else r=mid-1;
    }
    return b[res];
}
int main(){
    faster
    Eratosthenes_Sieve();
    cin >> n;
    for(int x, i=1; i<=n; ++i){
        cin >> x;
        if(prime[x]) a[++m] = x;
    }
    dp[1] = 1, b[1] = 1;
    int r=1;
    for(int i=2; i<=m; ++i){
        int k = binary(1, dp[r], a[i]);
        dp[i] = dp[k] + 1;
        b[dp[i]] = i;
        if(dp[i] > dp[r]) r=i;
    }
    cout << dp[r] << "\n";
}
/*5
11 2 3 4 7*/