#include<iostream>
#include<map>
using namespace std;
int n, cnt, ans;
map<int, int>mp;
int main(){
    cin >> n;
    for(int a, b, i=0; i<n; ++i)    cin >> a >> b, mp[a]++, mp[b]--;
    for(auto it : mp){
        cnt += it.second;
        ans = max(ans, cnt);
    }
    cout << ans;
}