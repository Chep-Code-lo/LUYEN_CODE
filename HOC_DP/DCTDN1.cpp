#include<bits/stdc++.h>
#define ll long long
#define N (int)2e5+5
#define FOR(i,l,r) for(int i = l ; i <= r ; i++)
#define FOD(i,r,l) for(int i = r ; i >= l ; i--)
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, a[N], res;
int main()
{
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    vector<int>f(n+1),b(n+1,INT_MAX);
    b[0] = INT_MIN;
    FOR(i,1,n){
        int k = lower_bound(b.begin(), b.end(), a[i] ) - b.begin();
        b[k] = a[i];
        f[i] = k;
        res = max(res, k);
    }
    cout << res << '\n';
    vector<int>v;
    for(int i=n; i>=1; i--){
        if(f[i] == res)
            v.push_back(i), res--;
    }
    //for(int i=v.size()-1; i>=0; i--)
        //cout << v[i] << ' ';
  
}
