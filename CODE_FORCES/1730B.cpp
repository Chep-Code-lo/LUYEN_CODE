#include<iostream>
#include<set>
using namespace std;
int t, n;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        set<int>se;
        for(char x : s) se.insert(x);
        cout << n + se.size() <<"\n";
    }
}
