#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;
int a, b, c, d;
int ans_1, ans_2, ans_3;
int main(){
    file_trau("TASK");
    cin >> a >> b >> c >> d;
    if(a >= b)  ans_1 = a;
    else   ans_1 = b;
    if(c >= d) ans_2 = c;
    else ans_2 = d;
    if(ans_1 >= ans_2) ans_3 = ans_1;
    else ans_3 = ans_2;
    cout << ans_3;
}