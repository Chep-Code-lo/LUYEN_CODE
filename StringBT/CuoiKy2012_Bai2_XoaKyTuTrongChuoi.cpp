#include <iostream>
#include <string>
using namespace std;
string S, vowels = "aeiouAEIOU", result = "";
int main(){
    getline(cin, S);
    for (char c : S)
        if(vowels.find(c) == string::npos)
            result += c;
    cout << result;
}