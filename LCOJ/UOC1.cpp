#include <iostream>
#include <math.h>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
int a, b, sum;
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> a >> b;
}
void solve(){
	faster
	//file("");
    input();
    for(int i=1; i<=sqrt(a); ++i){
    	if(a%i == 0){
    		if(b%i != 0)	sum += i;
    		int tmp = a/i;
    		if(b%tmp != 0)	sum += tmp;
    	}
    }
    cout << sum;
}
signed main(){
    solve();
    time();
}
