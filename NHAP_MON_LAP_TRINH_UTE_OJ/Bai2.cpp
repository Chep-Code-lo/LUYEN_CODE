#include<iostream>
#include<set>
using namespace std;
int n;
set<double>se;
int main(){
    cin >> n;
    for(double x, i=0; i<n; ++i) cin >> x , se.insert(x);
    cout << se.size();
}