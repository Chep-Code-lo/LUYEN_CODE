#include<iostream>
#include<algorithm>
using namespace std;
int a, b, cnt, digit_mark[10];
int main(){
    cin >> a >> b;
    while(a > 0){
        int digit = a%10;
        digit_mark[digit] = 1;
        a /= 10;
    }
    while(b > 0){
        int digit = b%10;
        if(digit_mark[digit] == 1){ 
            cnt++;
            digit_mark[digit] = 0;
        }
        b /= 10;
    }
    cout << (cnt == 1) ? 1 : 0;
}