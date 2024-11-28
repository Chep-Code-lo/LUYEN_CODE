#include <iostream>
#include <cmath>
using namespace std;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a){
        if (a == b && b == c) 
            cout << 0; // Tam giác đều
        else if (a == b || b == c || a == c) 
            cout << 1;  // Tam giác cân
        else if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b) 
            cout << 2;  
        else 
            cout << 3;  // Tam giác thường
    } else
        cout << 4;  // Không phải tam giác
}
