// Cre: Nguyễn Hoàng Luân
#include<iostream>
#include<algorithm>
using namespace std;
bool isPD(string str)
{
    string rev = str;reverse(rev.begin(),rev.end());
    return (str == rev);
}
int minL(string str)
{
    int len = str.length();
    for(int i = 0 ; i<len ; i++)
    {
        if(isPD(str.substr(i)))
        return i;
    }
    return len-1;
}
int main()
{
    string str;
    cin >> str;
    cout << minL(str);
}