#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int a[4];
int main(){
    file_chuan("TASK");
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a+4);
    cout << a[3];
}