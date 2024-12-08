#include <iostream>
#include <iomanip>
using namespace std;

double calculate_S(int n) {
    double sum = 1.0;
    double factorial = 1.0;

    for (int i = 1; i <= n; ++i){
        factorial *= i;
        sum += 1.0 / factorial;
    }

    return sum;
}

int main() {
    int n;
    cin >> n; // Nhập giá trị n
    cout << fixed << setprecision(2) << calculate_S(n) << endl; // In kết quả làm tròn 2 chữ số
    return 0;
}
