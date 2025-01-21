#include<bits/stdc++.h>
using namespace std;
int n, pos;
double x, a[101];
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i){
        double x, y; cin >> x >> y;
        a[i] = x/y;
    }
    for(int i=0; i<n; ++i)
        a[i] = abs(a[i] - x);
    double minn = *min_element(a, a+n);
    for(int i=0; i<n; ++i)
        if(minn == a[i]){
            cout << i;
            return 0;
        }
}
/*4
1.33
3 9 
4 6
10 12
5 7*/