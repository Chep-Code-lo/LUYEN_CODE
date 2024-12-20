#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long ans, x;
int main(){
    cin >> x;
    ans += x/3;
    x = x%3;
    ans += x/2;
    ans += x*2;
    cout << ans;
}