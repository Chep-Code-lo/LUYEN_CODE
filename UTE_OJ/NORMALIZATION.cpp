#include<iostream>
#include<sstream>
#include<string>
#include<cctype>
using namespace std;
string s;
int main(){
    getline(cin, s);
    for(int i=0; i<s.size(); ++i)
        if(!isalpha(s[i]) && !isspace(s[i]))
            s[i] = ' ';
    stringstream ss(s);
    string word, res = "";
    while(ss >> word){
        word[0] = toupper(word[0]);
        for(int i=1; i<word.size(); ++i)
            word[i] = tolower(word[i]);
        res += word + " ";
    }
    if(!res.empty())
        res.pop_back();
    cout << res;
}