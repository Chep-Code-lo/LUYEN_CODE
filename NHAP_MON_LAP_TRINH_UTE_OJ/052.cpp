#include<iostream>
#include<algorithm>
using namespace std;
int a[4];
int main(){
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a+4);
    if((a[0] + a[1] + a[2]) >= a[3] && (a[3] - a[2] == a[1] - a[0]))    cout << "YES";
    else    cout << "NO";
}