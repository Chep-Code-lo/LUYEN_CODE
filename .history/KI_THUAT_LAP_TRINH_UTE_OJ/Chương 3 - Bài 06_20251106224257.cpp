#include <iostream>
#include <iomanip>

int main() {
    int n;
    int x;

    std::cin >> n >> x;

    long double x_ld = (long double)x;
    long double sum = 1.0;

    for (int i = n; i > 0; --i) {
        sum = 1.0 + x_ld * sum / (long double)i;
    }

    std::cout << std::fixed << std::setprecision(2) << sum;

    return 0;
}