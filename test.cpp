#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

// Hàm chuyển đổi string lớn thành long double
long double stringToLongDouble(const std::string& s) {
    long double result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

int main() {
    std::string n;
    std::cin >> n;

    long double num = stringToLongDouble(n);
    long double cubeRoot = pow(num, 1.0L / 3.0L);

    std::cout << std::fixed << std::setprecision(10) << cubeRoot << std::endl;
    return 0;
}
