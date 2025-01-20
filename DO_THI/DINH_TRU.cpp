#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;
int n, m;
void input(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        dscanh.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
        sort(adj[i].begin(), adj[i].end());
}
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }  
    }
}
int tplt(){
    int ans = 0;
    for(int i=1; i<=n; ++i)
        if(!visited[i]){
            ++ans;
            DFS(i);
        }
    return ans;
}
int main(){
    input();
    int count = tplt();
    int cnt = 0;
    for(int i=1; i<=n; ++i){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(count < tplt())
            cnt++;
            // cout << i << " ";
    }
    cout << cnt;
}
/*10 6
10 1
5 2
10 5
10 6
5 3
10 4
*/