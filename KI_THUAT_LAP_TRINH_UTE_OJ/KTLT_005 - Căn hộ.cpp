#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m, k, cnt, a[200005];
multiset<int>se;
int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i)  cin >> a[i];
    for(int x, i=0; i<m; ++i)  cin >> x, se.insert(x);
    sort(a, a+n);
    for(int i=0; i<n; ++i){
        auto it = se.lower_bound( a[i]-k);
        if(it == se.end() || *it > a[i]+k) continue;
        se.erase(it);
        cnt++;
    }
    cout << cnt;
}   