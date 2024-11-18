#include <iostream>
#include<algorithm>
using namespace std;
int n, a[103];
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n, greater<int>());
    for(int i=1; i<n; ++i)
        if(a[0] != a[i]){
            cout << a[i];
            return 0;
        }
    cout << -1;
}