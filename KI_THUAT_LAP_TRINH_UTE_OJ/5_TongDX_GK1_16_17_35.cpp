#include<iostream>
using namespace std;
int n;
long long sum;
int main() {
    auto Pow = [](int n) -> int {
        int count = 1;
        while (n != 0) n /= 10, count *= 10;
        return count;
    };
    cin >> n;
    for (int i=1; i<=n; i++)
        sum += i * Pow(i) + i;
    cout << sum;
}