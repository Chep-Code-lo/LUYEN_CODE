#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m, cnt, t[50004];
multiset<int>se;
int main(){
    cin >> n >> m;
    for(int x, i=0; i<n; ++i)   cin >> x, se.insert(x);
    for(int i=0; i<m; ++i)  cin >> t[i];
    for(int i=0; i<m; ++i){
        auto it = se.upper_bound(t[i]);
        if(it == se.begin()) cout << -1 << "\n";
        else{
            it--;
            cout << *it << "\n";         
            se.erase(it);
        }
    }
}
/*5 3
5 3 7 8 5
4 8 3*/