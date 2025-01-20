#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;
int n, m, s, t, parent[1001];
// Danh sách kề
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v]){
            DFS(v);
            parent[v] = u;
        }  
}
void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        //cout << x << " ";
        for(int y : adj[x])
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
    }
}
int main(){
    cin >> n >> m >> s >> t;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
        sort(adj[i].begin(), adj[i].end());
    DFS(s);
    BFS(s);
    if(!visited[t]) cout << "-1";
    else{
        vector<int>res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s); 
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << " ";
    }
}
/*10 10 1 10
1 2
1 3
1 4
2 5
2 7
3 6
4 8
5 9
7 10
9 10
*/