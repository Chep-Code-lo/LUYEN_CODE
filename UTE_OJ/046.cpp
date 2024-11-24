#include<iostream>
using namespace std;
int n, cnt, x1, y1, x2, y2; 
bool check[101][101];
int main(){
    cin >> n;
    for(int k=0; k<n; ++k){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<=x2; ++i)
            for(int j=y1; j<=y2; ++j)
                check[i][j] = true;
    }
    for(int i=1; i<=100; ++i)
        for(int j=1; j<=100; ++j)
            if(check[i][j]) 
                cnt++;
    cout << cnt;
}