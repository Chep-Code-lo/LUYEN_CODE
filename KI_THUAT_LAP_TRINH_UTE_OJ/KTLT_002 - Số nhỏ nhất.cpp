#include <iostream>
#include <algorithm>
using namespace std;
int n;
string result = "";
int main() {
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
    while(n > 0){
        if (n >= 9){
            result += '9';
            n -= 9;
        }else{
            result += (n + '0');
            n = 0;
        }
    }
    sort(result.begin(), result.end());
    cout << result;
}
