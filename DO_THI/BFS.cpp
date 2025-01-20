#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;
int n, m, a[1001][1001];
// Danh sách kề
void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << " ";
        for(int y : adj[x])
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
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
            BFS(i);
            ++count;
        }
}
/*10 9
1 2
1 3
1 4
2 5
2 7
3 6
4 8
5 9
7 10
*/