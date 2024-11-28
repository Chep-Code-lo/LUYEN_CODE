
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, z;
    long long y;
    cin >> a;

    if (a <= 0.7)
        y = 12500;
    if (a <= 30)
        y = ceil(a - 0.7) * 17000 + 12500;
    if(a> 30)
        y = ceil(a - 30.7) * 14000 + 12500 + 30 * 17000;
    cout << y << endl;
}
