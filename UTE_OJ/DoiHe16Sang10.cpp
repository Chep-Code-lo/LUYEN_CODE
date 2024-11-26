#include<iostream>
#include<algorithm>
using namespace std;
int res;
string s;
long long Bin_Pow(long long a, long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1)// kiểm tra bit cuối bằng 1 không (tức b lẻ)
            res *= a;
        a*=a;
        b >>= 1;// Dịch b một bit sang phải (tức chia b cho 2)
    }
    return res;
}
int main(){
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); ++i){
        if(isdigit(s[i]))
            res = res + (s[i] - '0')*Bin_Pow(16, i);
        else
            res = res + (s[i] + 10 - 'A')*Bin_Pow(16, i);
    }
    cout << res;
}