#include<iostream>
using namespace std;
long long n, pascal[50][50];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<=i; ++j){
            if(j == 0 || j == i)
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    for(int i=0; i<n; ++i){
        for(int j=0; j<=i; ++j)
            cout << pascal[i][j] << " ";
        cout << "\n";
    }
}