#include <iostream>
using namespace std;

long long calculate_S(int n) {
    long long sum = 0;
    long long factorial = 1;

    for (int i = 1; i <= n; ++i){
        factorial *= i; 
        sum += factorial;
    }

    return sum;
}

int main() {
    int n;
    cin >> n; // Nhập giá trị n
    cout << calculate_S(n) << endl; // In kết quả
    return 0;
}
