#include<iostream>
#include<sstream>
#include<string>
using namespace std;
string s;
int main(){
    getline(cin,s);
    stringstream ss(s);
    string word, res = "";
    while(ss >> word){
        if(!res.empty()){
            res += " ";
        }
        res += word;
    }
    cout << res;
}