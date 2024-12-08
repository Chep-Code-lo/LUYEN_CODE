#include<iostream>
#include<set>
using namespace std;
set<int>se;
int n;
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i)   cin >> x, se.insert(x);
    cout << se.size();
}