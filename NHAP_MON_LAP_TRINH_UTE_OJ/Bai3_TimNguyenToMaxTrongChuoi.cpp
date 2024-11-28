#include<iostream>
using namespace std;
int n, maxx, digit;
bool check;
string s;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int main(){
    getline(cin, s);
    for(int i=0; i<s.size(); ++i){
        if(isdigit(s[i])){
            digit = digit*10 + (s[i] - '0');
            check = true;
        }
        else
            if(check){
                maxx = max(maxx, is_prime(digit) ? digit : 0);
                digit = 0;
                check = false;
            }
    }
    if(check && is_prime(digit))
        maxx = max(maxx, digit);
    cout << maxx;
}