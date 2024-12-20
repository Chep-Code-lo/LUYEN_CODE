#include<iostream>
using namespace std;
int m, a, b, c;
int main(){
    cin >> m >> a >> b >> c;
    int col_1 = min(m, a);
    int col_2 = min(m, b);
    int col_3 = min(2*m - col_1 - col_2, c);
    cout << col_1 + col_2 + col_3;
}