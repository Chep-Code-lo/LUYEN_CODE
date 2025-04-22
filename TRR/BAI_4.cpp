#include <iostream>
#include <vector>
using namespace std;
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
const int N = 1e3 + 5;
int s, n, sum, a[N][N];
void print_time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
    cin >> s >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) cin >> a[i][j], sum += a[i][j];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(i == j || a[i][j] == 0)
                a[i][j] = sum;
}
void truy_vet(int v, const vector<int>& truoc){
    if(v == -1) return;
    vector<int>add;
    while(v != -1 && v != truoc[v]){
        add.push_back(v);
        v = truoc[v];
    }
    add.push_back(v);
    reverse(add.begin(), add.end());
    for(int i=0; i<add.size(); ++i){
        cout << add[i];
        if(i < add.size() - 1) cout << " -> ";
    }
    cout << "\n";
}
void Ford_Bellman(){
    file("Ford");
    faster;
    input();
    //sum = 32;
    vector<int> d(n, sum);
    vector<int> truoc(n, -1);
    for(int v=0; v<n; ++v){
    	d[v] = a[s][v];
    	truoc[v] = s;
    }
    d[s] = 0;
    for(int k=1; k<n-1; ++k)
    	for(int v=0; v<n; ++v){
    		if(d[v] == s)	continue; 
	    	for(int u=0; u<n; ++u)
	    		if(d[v] > d[u] + a[u][v]){
	    			d[v] = d[u] + a[u][v];
	    			truoc[v] = u;
	    		}
    	}
    for(int v=1; v<n; ++v){
        cout << "d[" << v << "] = " << d[v] << " Duong di tu " << s << " toi " << v << ": ";
        if(d[v] == sum) cout << "Khong co duong di\n";
        else truy_vet(v, truoc); 
    }

}
signed main(){
    Ford_Bellman();
    print_time();
}
