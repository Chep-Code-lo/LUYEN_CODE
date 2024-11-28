/*Cre: Chat GPT*/
#include <iostream>
#include<algorithm>
using namespace std;
int a, b, c, cnt;
int main() {
    cin >> a >> b >> c;
    if (c % __gcd(a, b) != 0){
        cout << -1;
        return 0;
    }
    for (int x = 1; x <= c / a; x++){
        double y = (c - a * x) / (double)b;
        
        if (y > 0 && y == (int)y)
            cnt++;
    }
    cout << cnt;
}
