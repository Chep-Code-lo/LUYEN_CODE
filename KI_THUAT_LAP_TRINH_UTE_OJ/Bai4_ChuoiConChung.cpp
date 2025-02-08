#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int f[2001][2001];
string a, b;
int main(){
    getline(cin, a);
    getline(cin, b);
    a = "#" + a;
    b = "#" + b;
    for(int i=1; i<a.size(); ++i)
        for(int j=1; j<b.size(); ++j){
            if(a[i] == b[j])    f[i][j] = f[i-1][j-1] + 1;
            f[i][j] = max({f[i][j], f[i-1][j], f[i][j-1]});
        }
    cout << f[a.size()-1][b.size()-1];
}
