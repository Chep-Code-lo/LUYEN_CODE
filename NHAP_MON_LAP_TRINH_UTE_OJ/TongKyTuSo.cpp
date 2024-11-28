#include<iostream>
using namespace std;
string s;
long long sum;
int main(){
    getline(cin, s);
    for(int i=0; i<s.size(); ++i)
        if(isdigit(s[i]))
            sum += (s[i] - '0');
    cout << sum;
}
