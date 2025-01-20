#include<iostream>
using namespace std;
int n, m, a[1001][1001];
// Danh sách cạnh sang ma trận kề (đồ thị vô hướng)
int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u, v; cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
/*5 4
4 3
3 1
4 2
5 4
*/