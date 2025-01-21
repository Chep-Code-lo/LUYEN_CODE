// Author : Chép Code Lỏ
// Github : @Chep-Code-lo
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define file(name) freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);
using namespace std;
int ddir[2][2]={{0,1},{1,0}};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dir3[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
void time(){
    cerr << "=> Time code run: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " s" << string(27, '\t');
}
string Cube(string n){
    reverse(n.begin(), n.end());
    vector<int> square(2 * n.size()), cube(3 * n.size());
    for(int i=0; i<n.size(); ++i)
        for(int j=0; j<n.size(); ++j) 
            square[i + j] += (n[i] - '0') * (n[j] - '0');
    for(int i=0; i<n.size(); ++i)
        for(int j=0; j<square.size(); ++j) 
            cube[i + j] += (n[i] - '0') * square[j];
    string res = "";
    for(int i=0, current=0; i<cube.size(); ++i){
        current += cube[i]; 
        res += current % 10 + '0'; 
        current /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string Cube_Root(string n){
    n = string((3 - n.size() % 3) % 3, '0') + n;
    string D = "", R = "";
    char d;
    for(int i=0; i<n.size(); i+=3){ 
        for(D += n.substr(i, 3), d = '9'; Cube(R + d) > D; d--); R += d;
    }
    for(int i=0; i<10; ++i){ 
        for(D += "000", d = '9'; Cube(R + d) > D; --d); R += d;
    }
    R.insert(R.size() - 10, ".");
    return R;
}
string s;
int main(){
    cin >> s;
    cout << Cube_Root(s);
    time();
}