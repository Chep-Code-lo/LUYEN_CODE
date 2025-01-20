#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;
int n, m, a[1001][1001];
// Danh sách kề
void DFS1(int u){
    cout << u << " ";
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v])
            DFS1(v);
}
//Ma trận kề
void DFS2(int u){
    cout << u << " ";
    visited[u] = true;
    for(int i=1; i<=n; ++i)
        if(a[u][i] == 1)
            if(!visited[i])
                DFS2(i); 
}
//Danh sách cạnh
void DFS3(int u){
    cout << u << " ";
    visited[u] = true;
    for(auto it : dscanh){
        if(it.first == u)
            if(!visited[it.second])
                DFS3(it.second);
        if(it.second == u)
            if(!visited[it.first])
                DFS3(it.first);
    }

}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    //Đếm số thành phần liên thông
    for(int i=1; i<=n; ++i)
        if(!visited[i]){
            DFS1(i);
            ++count;
        }
}
/*9 8
1 2
1 6
2 3
2 4
3 5
6 7
7 8
7 9
*/