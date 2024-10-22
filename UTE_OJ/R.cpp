#include<iostream>
#include<set>
using namespace std;
int n, a[1003];
set<int>se;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], se.insert(a[i]);
    for(int x : se) cout << x << " ";
}