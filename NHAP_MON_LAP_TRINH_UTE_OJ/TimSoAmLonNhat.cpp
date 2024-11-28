#include<iostream>
#include<algorithm>
using namespace std;
int n, minn, a[202];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; ++i)
        if(a[i] < 0){
            minn = a[i];
            break;
        }
    cout << minn;
}