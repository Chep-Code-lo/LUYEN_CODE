#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
using namespace std;
string matrix[50], save[55];
int n, index;
int main(){
    //file("test");
    while(cin >> matrix[n]){
        n++;
    }
    for(int i=0; i<n; ++i)
        save[index++] = matrix[i];
    for(int j=0; j<n; ++j){
        string col = "";
        for(int i=0; i<n; ++i)
            col += matrix[i][j];
        save[index++] = col;
    }
    string diag_main = "";
    for (int i=0; i<n; i++)
        diag_main += matrix[i][i];
    save[index++] = diag_main;
    string diag_anti = "";
    for (int i = 0; i < n; i++)
        diag_anti += matrix[i][n - 1 - i];
    save[index++] = diag_anti;
    cout << *min_element(save, save + 2*n +2 );
}