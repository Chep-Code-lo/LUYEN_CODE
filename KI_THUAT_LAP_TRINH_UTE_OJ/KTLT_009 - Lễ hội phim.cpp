#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FOD(i,r,l) for(int i = r ; i >= l ; i--)
#define faster cin.tie(0)->sync_with_stdio(0);
using namespace std;
struct Data{
    int st, end;
    bool operator < (const Data &other) const {
        return end < other.end;
    }
}a[N];
int n, cnt, s[N], dp[N];
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i].st >> a[i].end;
    sort(a, a+n);
    int end_time = a[0].end;
    for(int i=0; i<n; ++i)  s[i] = a[i].end;
    dp[0] = 1;
    for(int i=1; i<n; ++i)
        if(a[i].st >= end_time){
            end_time = a[i].end;
            cnt++;
        }
    for(int i=0; i<n; ++i){
        int p = upper_bound(s, s+n, a[i].st) - s - 1;
        dp[i] = max(dp[i-1], dp[p] + 1);
    }
    cout << dp[n-1];
    //cout << cnt;
}
