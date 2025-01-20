#include<bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool visited[1000][1000];
vector<string>matrix(1000);
pair<int, int> start, des;
void input(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> matrix[i];
        for(int j=0; j<m; ++j){
            if(matrix[i][j] == 'A') start = {i, j};
            else if(matrix[i][j] == 'B') des = {i, j};
        }
    }
}
void bfs(){
    queue<pair<int, int>>q;
    q.push(start);
    visited[start.first][start.second] = true;
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; ++i){
            //auto [x, y] = q.front(); q.pop();
            auto top = q.front(); q.pop();
            if(top.first == des.first && top.second == des.second){
                cout << steps;
                return;
            }
            //for(auto [dx, dy] : dir)
            for(int i=0; i<4; ++i){
                int nx = top.first + dir[i][0];
                int ny = top.second + dir[i][1];
                 if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (matrix[nx][ny] == '.' || matrix[nx][ny] == 'B')){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                 }
            }
        }
        steps++;
    }
    cout << -1;
}
int main(){
    input();
    bfs();
}
/*5 8
########
#.A#...#
#.##.#B#
#......#
########*/   