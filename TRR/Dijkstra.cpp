#include <iostream>
#include <vector>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
const int N = 1e3+1;
int s, n, sum, a[N][N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> s >> n;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)	cin >> a[i][j], sum += a[i][j];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(i != j && a[i][j] == 0)
				a[i][j] = sum;
}
int find_min(const vector<int>& T, const vector<int>& d) {
    if (T.empty())
        return -1; // Không có đỉnh nào trong T.

    // Khởi tạo với đỉnh đầu tiên trong T
    int minVertex = T[0];
    // Duyệt qua tất cả các đỉnh trong T
    for (int v : T) {
        if (d[v] < d[minVertex])
            minVertex = v;
    }
    return minVertex;
}
void solve(){
	faster
	//file("");
    input();
    vector<int> d(n, sum);
    vector<int> truoc(n, -1);
    d[s] = 0;  
    vector<int>t;
    for(int i=1; i<=n; ++i){
        d[i] = a[s][i];
        truoc[i] = s;
    }
    d[s] = 0;
    for(int i=1; i<=n; ++i)
    	if(i != s)
    		t.push_back(i);
    //for(int i=0; i<t.size(); ++i)	cout << t[i] << " ";
    while(!t.empty()){
        int min_post = find_min(t, d);
        cout << min_post << " ";
        t.erase(t.begin() + min_post);
        //cout << t.size() << " ";
        for(int i=0; i<t.size(); i++){
            if (d[i] > d[min_post] + a[min_post][i]){
                d[i] = d[min_post] + a[min_post][i];
                truoc[i] = min_post;
            }
        } 
    }
    //for(int i=0; i<n; ++i)	cout << d[i] << " ";
}
signed main(){
    solve();
    print_time();
}
