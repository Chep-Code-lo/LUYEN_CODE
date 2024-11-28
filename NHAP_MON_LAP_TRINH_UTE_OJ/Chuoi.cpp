#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
string s, word, res = "", ans = "", result = "";
int main(){
    getline(cin, s);
    stringstream ss (s);
    while(ss >> word){
        if(word.size() > ans.size())
            ans = word;
        res += word + " ";
    }
    if(!res.empty())
        res.pop_back();
    cout << s << "\n";
    reverse(s.begin(), s.end());
    cout << s << "\n";
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); ++i)
        if(s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i] << "\n";
    cout << ans << "\n";
    cout << res;
}
/*Dh       Spkt      Tp.hcm
        khoa    cntt*/