#include<iostream>
using namespace std;
int n, count, a[1005];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(abs(a[i])%2 == 0) count++;
    } 
    cout << count << "\n";
}