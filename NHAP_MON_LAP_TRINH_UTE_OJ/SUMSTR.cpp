#include<iostream>
using namespace std;
string s;
int n, digit;
long long sum;
bool check;
int main(){
    cin >> n;
    cin >> s;
    for(int i=0; i<n; ++i){
        if(isdigit(s[i])){
            digit = digit*10 + (s[i]-'0');
            check = true;
        }
        else
            if(check){
                sum += digit;
                digit = 0;
            }
        //cout << digit << " ";    
    }
    cout << sum;
}