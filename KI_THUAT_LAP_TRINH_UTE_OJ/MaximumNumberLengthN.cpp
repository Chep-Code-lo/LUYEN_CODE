#include<iostream>
#include<algorithm>
using namespace std;
int n, s;
string res="";
int main(){
    cin >> n >> s;
    if(s > 9 * n || (s == 0 && n > 1)){
        cout << -1;
        return 0;
    }
    while(n--){
        if(s > 9){
            s -= 9;
            res += 9 + '0';
        }
        else{
            res += s + '0';
            s -= s;
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    cout << res;
}