#include<iostream>
using namespace std;
int n, pos, maxx, a[1003];
bool check_1 = true, check_2 = true;
int main(){
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i], maxx = max(maxx, a[i]);
    for(int i=n-1; i>=0; --i)
        if(maxx == a[i]){
            pos = i;
            break;
        }
    for(int i=0; i<pos; ++i)
        if(a[i] >= a[i+1]){
            check_1 = false;
            break;
        }
    for(int i=pos; i<n-1; ++i)
        if(a[i] <= a[i+1]){
            check_2 = false;
            break;
        }
    cout << (check_1 && check_2 ? "YES" : "NO");
}