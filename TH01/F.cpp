#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
    cin >> s;
    string res ="";
    int i=0;
    while (i < s.length())
    {
        int cnt = 0;
        while (i<s.length() && isdigit(s[i]))
        {
            cnt = cnt*10 + (s[i] - '0');
            i++;
        }
        string sub ="";
        while (i<s.length() && isalpha(s[i]))
        {
            sub += s[i];
            i++;
        }
        for(int j=0; j<cnt; ++j)
            res += sub;  
    }
    cout << res;
}