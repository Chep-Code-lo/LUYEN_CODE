#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
string s, word;
int cnt;
int main(){
    getline(cin, s);
    stringstream ss (s);
    while(ss >> word){
        cnt++;
    }
    cout << cnt;
}