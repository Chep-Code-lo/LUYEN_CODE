#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int n, m, maxx = -1e10, cnt, a[1003][1003];
long long x;
signed main(){
    //file_chuan("TASK");
    cin >> x;
    x = abs(x);
    long long steps_3 = x / 3;
    long long remainder = x % 3;
    long long steps_2 = 0;
    if(remainder == 1){
        if(steps_3 >= 1){
            steps_3 -= 1;
            steps_2 = 2;
        } else {
            steps_3 = 0;
            steps_2 = 1;
        }
    }
    else if(remainder == 2)
        steps_2 = 1;
    cout << steps_2 + steps_3;
}