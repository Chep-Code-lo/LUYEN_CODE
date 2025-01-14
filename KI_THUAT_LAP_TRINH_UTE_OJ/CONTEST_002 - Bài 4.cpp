//Author: Chép-Code-lỏ
//Github: @Chep-Code-lo
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longest(vector<string>&str){
    if(str.empty()) return "";
    string temp = str[0];
    for(int i=1; i<str.size(); ++i)
        while(str[i].find(temp) != 0){
            temp = temp.substr(0, temp.size() - 1);
            if(temp.empty()) return "";
        }
    return temp;
}
int n;
int main(){
    cin >> n;
    vector<string>str(n);
    for(int i=0; i<n; ++i)  cin >> str[i];
    cout << longest(str);
}