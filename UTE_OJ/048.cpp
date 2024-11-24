#include<iostream>
using namespace std;
int n, a[102][102], b[102][102];
int main(){
    cin >> n ;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) cin >> a[i][j];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            b[j][n-1-i] = a[i][j];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cout << b[i][j] << " ";
        cout << "\n";
    }
}