//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
#include<set>
using namespace std;
int n, m;
set<long>a;
int main(){
    cin >> n >> m;
    for(int x,i=0; i<n; ++i)    cin >> x, a.insert(x);
    for(int x,i=0; i<m; ++i)    cin >> x, a.insert(x);
    for(auto it : a)    cout << it << " ";
}
/*4 6
2 5 5 5
2 2 3 5 5 7*/