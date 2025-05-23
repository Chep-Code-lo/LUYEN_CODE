#include <iostream>
#include <string>
#include <algorithm>
#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
string s;
int cnt, dp[1001][1001];
void time(){
    cerr << "Time elapsed: ";
    cerr << TIME << "s.\n";
}
void input(){
	cin >> s;
}
/*void count_odd(){
    for(int i=0; i<s.size(); ++i)
        for(int j=1; i-j>=0 && i+j<s.size(); ++j){
            int diff_cnt = 0;
            for(int r=1; r<=j; ++r){
                if(s[i-r] != s[i+r])
                    diff_cnt++;
            }
            if(diff_cnt == 1 || (diff_cnt == 0 && j > 0))   cnt++;
        }
}
void count_even(){
    for(int i=0; i<s.size()-1; ++i)
        for(int j=0; i-j>=0 && i+j+1<s.size(); ++j){
            int diff_cnt = 0;
            for(int r=0; r<=j; ++r)
                if(s[i-r] != s[i+r+1])
                    diff_cnt++;
            if(diff_cnt == 1) cnt++;
        }
}*/
void solve(){
	faster
	//file("");
    input();
    //count_odd();
    //count_even();
    int n = s.size();
    cnt = n;
    for(int l=2; l<=n; ++l)
        for(int i=0; i+l-1<n; ++i){
            int j = i+l-1;
            if(l == 2)  dp[i][j] = (s[i] != s[j]);
            else dp[i][j] = dp[i+1][j-1] + (s[i] != s[j]);
             if(l%2 == 1){
                // odd-length ≥3
                if(dp[i][j] <= 1) 
                    cnt++;
            }else{
                // even-length ≥2
                if(dp[i][j] == 1)
                    cnt++;
            }
        }
    cout << cnt;
}
signed main(){
    solve();
    time();
}
