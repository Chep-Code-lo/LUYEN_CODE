#include<iostream>
using namespace std;
int a, b, c, d;
int main(){
    cin >> a >> b >> c >> d;
    if(b >= c && a <= d) cout << "YES";
    else cout << "NO";
}