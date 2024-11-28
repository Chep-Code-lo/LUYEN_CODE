#include<iostream>
using namespace std;
int n, count, a[103];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n-1; ++i)
        if(a[i] == a[i+1]){
            count++;
            while(i < n-1 && a[i] == a[i+1]){
                i++;
            }
        }
    cout << count;
}