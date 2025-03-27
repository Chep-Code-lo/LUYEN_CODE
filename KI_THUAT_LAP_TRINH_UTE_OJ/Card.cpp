#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
struct event{
	int x, y1, y2;
	bool operator<(const event& other)	const{
		return x < other.x;
	} 
};
struct node{
	bool flip_lazy = false;
	int white_len = 0, total_len = 0;
};
int m, n, k, num_y;
vector<int>y_coords;
vector<node>tree;
set<int> y_set;
vector<event>events;
void build(int node, int l, int r){
	if(l > r) return;
	if(l == r){
		tree[node].total_len = y_coords[l+1] - y_coords[l];
		tree[node].white_len = tree[node].total_len;
	}
	else{
		int mid = (l+r)/2;
		build(2*node+1, l, mid);
		build(2*node+2, mid+1, r);
		tree[node].total_len = tree[2*node+1].total_len + tree[2*node+2].total_len;
		tree[node].white_len = tree[2*node+1].white_len + tree[2*node+2].white_len;
		tree[node].flip_lazy = false;
	}
}
void push(int node, int l, int r){
	if(tree[node].flip_lazy && l != r){
		tree[2*node+1].flip_lazy = !tree[2*node+1].flip_lazy;
		tree[2*node+1].white_len = tree[2*node+1].total_len - tree[2*node+1].white_len;
		tree[2*node+2].flip_lazy = !tree[2*node+2].flip_lazy;
		tree[2*node+2].white_len = tree[2*node+2].total_len - tree[2*node+2].white_len;
		tree[node].flip_lazy = false;
	}
}
void update(int node, int l, int r, int u, int v){
	if(l > r || u > r || v < l)	return;
	if(u <= l && r <= v){
		tree[node].flip_lazy = !tree[node].flip_lazy;
		tree[node].white_len = tree[node].total_len - tree[node].white_len;
	}
	else{
		push(node, l, r);
		int mid = l + (r-l)/2;
		update(2*node+1, l, mid, u, v);
		update(2*node+2, mid+1, r, u, v);
		tree[node].white_len = tree[2*node+1].white_len + tree[2*node+2].white_len;
	}
}
void input(){
	cin >> m >> n >> k;
	y_set.insert(1);
	y_set.insert(m+1);
	for(int i=0; i<k; ++i){
		int a, b, c, d; cin >> a >> b >> c >> d;
		y_set.insert(a); y_set.insert(b+1);
		events.push_back({c, a, b+1});
		events.push_back({d+1, a, b+1});
	}
}
void solve(){
	faster
	//file("");
    input();
    y_coords.assign(y_set.begin(), y_set.end());
    num_y = y_coords.size() - 1;
    map<int, int> y_map;
    for(int i = 0; i<y_coords.size(); ++i) y_map[y_coords[i]] = i;
   	if(num_y > 0){
        tree.resize(4 * num_y); 
        build(0, 0, num_y - 1);
    }else{
         if(m > 0 && m > 0) cout << m*n;
         else cout << 0;
         return;
    }
    sort(events.begin(), events.end());
    int total_white_area = 0;
    int prev_x = 1;
    for(int i=0; i<events.size(); ){
        int current_x = events[i].x;
        int dx = current_x - prev_x;
        if(dx > 0){
            int current_total_white_y_length = tree[0].white_len;
            total_white_area += dx * current_total_white_y_length;
        }
        int j = i;
        while(j<events.size() && events[j].x == current_x){
        	int r1 = y_map[events[j].y1];
            int r2 = y_map[events[j].y2];
            if(r1 < r2)	update(0, 0, num_y - 1, r1, r2 - 1);
            j++;
        }
        prev_x = current_x;
        i = j;
    }
    if(prev_x <= n){
    	int dx = (n+1) -prev_x;
    	if(dx > 0){
    		int current_total_white_y_length = tree[0].white_len;
    		total_white_area += dx*current_total_white_y_length;
    	}
    }
    cout << total_white_area;
}
signed main(){
    solve();
    time();
}
