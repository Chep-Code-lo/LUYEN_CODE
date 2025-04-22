#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 100+1;
int n, a[N][N], chuaxet[N];
vector<pair<int, int>>T;
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		chuaxet[i] = 1;	
		for(int j=1; j<=n; ++j)	cin >> a[i][j];
	}
}
void Tree_BFS(int r){
	queue<int>q;
	q.push(r);
	chuaxet[r] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u=1; u<=n; ++u)
			if(a[v][u] == 1 && chuaxet[u]){
				q.push(u);
				chuaxet[u] = 0;
				T.push_back({v, u});
			}
	}
}
void solve(){
	faster
	file("BFS");
    input();
    Tree_BFS(1);
    for(auto x : T)
    	cout << x.first << " " << x.second << "\n";
}
signed main(){
    solve();
    print_time();
}
