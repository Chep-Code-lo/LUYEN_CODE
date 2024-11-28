#include<iostream>
using namespace std;
string s;
int count;
bool is_prime(int x){
    if(x <= 1) return false;
    if(x <= 3) return true;
    if(x%2 == 0 || x%3 == 0) return false;
    for(int i=5; i*i<=x; i+=6)
        if(x%i == 0 || x%(i+2) == 0) return false;
    return true;
}
int main(){
    cin >> s;
    for(int i=0; i<s.size(); ++i)
        if(is_prime(s[i] - '0'))
            count++;
    cout << count;
}