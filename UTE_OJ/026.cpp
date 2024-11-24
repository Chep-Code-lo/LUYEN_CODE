#include<iostream>
using namespace std;
int limit, maxx, a[1003];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i) cin >> a[i];
    for(int i=0; i<limit-1; ++i)  maxx = max(maxx, abs(a[i+1] - a[i]));
    cout << maxx << "\n";
}