//Author: Chép Code Lỏ
//Github: @Chep-Code-lo
#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int times[1001][1001];
int n, m, maxtime;
char a[1001][1001];
queue<pair<int, pair<int,int>>> pq;
void input(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)  cin >> a[i][j];
}
void dfs(int x, int y, int time){
    maxtime = max(maxtime, time);
    for(auto& it : dir){
        int nx = x + it[0];
        int ny = y + it[1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1'){
            a[nx][ny] = '2';
            dfs(nx, ny, time+1);
        }
    }
}
void bfs(){
    while(!pq.empty()){
        auto top = pq.front(); pq.pop();
        for(int i=0; i<4; ++i){
            int nx = top.second.first + dir[i][0], ny = top.second.second + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1'){
                a[nx][ny] = '2';
                times[nx][ny] = top.first + 1;
                pq.push({times[nx][ny], {nx, ny}});

            }
        }
    }
}
void solve(){
    input();
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(a[i][j] == '2')
                pq.push({0, {i, j}});
    bfs();
    int ans = -1;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            if(a[i][j] == '1'){
                cout << -1;
                return;
            }
            ans = max(ans, times[i][j]);
        }
    cout << ans;
}
signed main(){
    solve();
}
/*3 3
211
110
011*/