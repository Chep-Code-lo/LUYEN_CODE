#include <iostream>
#include <vector>
#include <algorithm>
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
using namespace std;
const int N = 1e3 + 5;
int s, n, sum, a[N][N];
void input(){
    cin >> s >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) cin >> a[i][j], sum += a[i][j];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            if(i == j || a[i][j] == 0)
                a[i][j] = sum;
}
int find_min(const vector<int>& T, const vector<int>& d){
    int minn = T[0];
    for(int v : T){
        if(d[v] < d[minn])
            minn = v;
    }
    return minn;
}
void truy_vet(int v, const vector<int>& truoc){
    if(v == -1) return;
    vector<int>add;
    while(v != -1 && v != truoc[v]){
        add.push_back(v);
        v = truoc[v];
    }
    add.push_back(v);
    reverse(add.begin(), add.end());
    for(int i=0; i<add.size(); ++i){
        cout << add[i];
        if(i < add.size() - 1) cout << " -> ";
    }
    cout << "\n";
}
void solve(){
    //file("bai3");
    input();
    //sum = 32;
    vector<int> d(n + 1, sum);
    vector<int> truoc(n + 1, -1);
    vector<int> T;
    for(int v=1; v<=n; ++v){
        d[v] = a[s][v];
        truoc[v] = s;
    }
    for(int i=1; i<=n; ++i){
        if(i == s) continue;
        T.push_back(i);
    }
    /*for(int x : T)  cout << x << " ";
    cout << "\n";*/
    d[s] = 0;
    while(!T.empty()){
        int u = find_min(T, d);
        cout << u << "\n";
        auto it = find(T.begin(), T.end(), u);
        if(it != T.end()) T.erase(it);
        for(int v : T)
            if(d[v] > d[u] + a[u][v]){
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
    }
    for(int v=1; v<=n; ++v){
        cout << "d[" << v << "] = " << d[v] << " Duong di tu " << s << " toi " << v << ": ";
        if(d[v] == sum) cout << "Khong co duong di\n";
        else truy_vet(v, truoc); 
    }

}
signed main(){
    solve();
}
