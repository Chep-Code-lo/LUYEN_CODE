#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,x;
    ll demm = 0;
    ll s=0;
    cin>>n>>x;
    vector<ll> a(n);    
    for (ll i = 0; i<n;i++)
        cin >> a[i];
    for (ll i=0;i<n;i++) {
        if (a[i]% x!=0) {
            s+=a[i];
            demm++;
        }
    }
    if(demm==0)
    cout<<0;
    else
        cout<<(s+demm/2)/demm;
}