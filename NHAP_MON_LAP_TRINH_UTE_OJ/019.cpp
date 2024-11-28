#include<iostream>
using namespace std;
int a, b, cnt;
int main(){
    cin >> a >> b;
    if(10 <= a && a <= 20)
        cnt++;
    if(10 <= b && b <= 20)
        cnt++;
    cout << (cnt == 1) ? 1 : 0;
}