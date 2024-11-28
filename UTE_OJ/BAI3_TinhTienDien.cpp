#include<iostream>
using namespace std;
#define ll long long
ll n, s;
int main(){
    cin >> n;
    if(n<=48) 
        s = n*600;
     else 
        if(n<=96) 
        s = 48*600 + (n-48)*1004;
        else 
            if(n<=144) 
        s= 48*600 + 48*1004 + (n-96)*1214;
     else 
        s = 48*600 + 48*1004 + 48*1214 + (n-144)*1594;
    cout << s;
}