#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>adj[1001];
int n, m;
// Chuyển danh sách cạnh sang danh sách kề (đồ thị vô hướng)
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i){
        sort(adj[i].begin(), adj[i].end());
        cout << i << ":";
        for(int x : adj[i]) cout << x << " ";
        cout << "\n";
    }
}
/*5 4
4 3
3 1
4 2
5 4
*/