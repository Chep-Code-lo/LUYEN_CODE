#include<iostream>
#include<algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;

long long A[1000][1000];
long long x, step_2, step_3; 
int main() {
    file_trau("TASK");
    cin >> x;
    x = abs(x);
    while(step_3*3 <= x){
        step_3++;
    }
    x -= step_3*3;
    while (step_2*2 <= x){
        step_2++;
    }
    cout << step_2+step_3;
}