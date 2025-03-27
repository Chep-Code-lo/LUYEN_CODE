#include <iostream>
#include <utility>
#include <vector>
#include <map>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int n, m, q;
vector<vector<char>> grid(501, vector<char>(501));
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)  cin >> grid[i][j];
    cin >> q;
}

pair<int, int> move(int x, int y, vector<vector<char>>& grid){
    char dir = grid[x][y];
    if(dir == '^') return {x - 1, y};
    if(dir == 'v') return {x + 1, y};
    if(dir == '<') return {x, y - 1};
    if(dir == '>') return {x, y + 1};
    return {x, y};
}
void solve(){
    faster
    // file("");
    input();
    while(q--){
        int x, y;
        long long k;
        cin >> x >> y >> k;
        x--; y--;
        map<pair<int, int>, long long> visited;
        long long steps = 0;
        while(steps < k){
            if(visited.count({x, y})){
                long long cycle_length = steps - visited[{x, y}];
                long long remaining_steps = k - steps;
                steps += (remaining_steps / cycle_length) * cycle_length;
                if (steps >= k) break;
            }
            visited[{x, y}] = steps;
            auto next = move(x, y, grid);
            x = next.first;
            y = next.second;
            steps++;
        }
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

signed main(){
    solve();
    time();
}