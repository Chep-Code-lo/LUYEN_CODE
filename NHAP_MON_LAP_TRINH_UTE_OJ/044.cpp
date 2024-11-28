#include<iostream>
using namespace std;
int n, m, x, y, a[15][15], b[15][15];
bool check = false;
int main(){
    cin >> n >> m >> x >> y;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) cin >> a[i][j];
    for(int i=0; i<x; ++i)
        for(int j=0; j<y; ++j) cin >> b[i][j];
    for(int i=0; i<=n-x; ++i){
        for(int j=0; j<=m-y; ++j){
            bool YES = true;
            for(int l=0; l<x; ++l){
                for(int r=0; r<y; ++r)
                    if(a[i+l][j+r] != b[l][r]){
                        YES = false;
                        break;
                    }
                if(!YES) break;
            }
            if(YES){
                check = true;
                break;
            }
        }
        if(check) break;
    }
    cout << (check ? "YES" : "NO");
    
}