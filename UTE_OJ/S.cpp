#include<iostream>
#include<map>
using namespace std;
int n, count, a[1003];
map<int, int>mp;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], mp[a[i]]++;
    for(auto it : mp)
        if(it.second > 2)   count++;
    cout << count;
    
}