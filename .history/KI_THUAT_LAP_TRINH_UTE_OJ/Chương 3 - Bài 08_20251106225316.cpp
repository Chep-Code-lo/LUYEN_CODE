#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A;                      
    if (!(cin >> A)) return 0;

    double sum = 0.0;
    int n = 0;
    while (sum <= A) {
        ++n;
        sum += 1.0 / n;
    }
    cout << n;
    return 0;
}
