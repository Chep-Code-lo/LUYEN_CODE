#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int main(){
    getline(cin,s);
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp,'.')){
        cout << tmp <<"\n";
    }
}