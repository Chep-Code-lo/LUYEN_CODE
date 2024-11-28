#include<iostream>
using namespace std;
int n, m, sum, cnt, a[103][103];
int main(){
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) cin >> a[i][j];
    // hang dau
    for(int j=0; j<n; ++j)
        if(a[0][j]%5 == 0){
            sum += a[0][j];
            if(a[0][j] != 0)
                cnt++;
        }
    // cot phai
    for(int i=1; i<m; ++i)
        if(a[i][n-1]%5 == 0){
            sum += a[i][n-1];
            if(a[i][n-1] != 0)
                cnt++;
        }
    // hang cuoi    
    for(int j=0; j<n-1; ++j)
        if(a[m-1][j]%5 == 0){
            sum += a[m-1][j];
            if(a[m-1][j] != 0)
                cnt++;
        }  
    // cot trai
    for(int i=1; i<m-1; ++i)
        if(a[i][0]%5 == 0){
            sum += a[i][0];
            if(a[i][0] != 0)
                cnt++;
        }
    if(cnt == 0) cout << -1;
    else{
        double x = sum/cnt;
        int res = int(x);
        cout << res;
    }
}
/*4 5
1 3 5 7 9
36 39 42 45 12
33 54 51 48 15 
30 27 24 21 18*/