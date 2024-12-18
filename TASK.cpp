#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int n, m, maxx = -1e10, cnt, a[1003][1003];
signed main(){
    file_chuan("TASK");
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) cin >> a[i][j], maxx = max(maxx, a[i][j]);
    for(int i=0; i<n; ++i){
        int max_i = -1e10, cnt_max = 0;
        for(int j=0; j<m; ++j)
            max_i = max(max_i, a[i][j]);
        for(int j=0; j<m; ++j)
            if(a[i][j] == max_i)
                cnt_max++;
        //cout << cnt_max << "\n";
        if(max_i < maxx){
            cnt++;
            cnt += (cnt_max-1);
        }
    }
    cout << cnt;
        
}