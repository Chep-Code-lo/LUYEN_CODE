#include <bits/stdc++.h>
using namespace std;
string multiply(const string &a, const string &b) {
    vector<int> res(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = res[i + j + 1] + mul;
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string result;
    for (int num : res)
        if (!(result.empty() && num == 0))
            result.push_back(num + '0');
    return result.empty() ? "0" : result;
}

// Hàm tính giá trị chính phương của một số lớn
string power(const string &base, int exp) {
    string result = "1", temp = base;
    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, temp);
        temp = multiply(temp, temp);
        exp >>= 1;
    }
    return result;
}

// Hàm nhân hai chuỗi số lớn

// Phương pháp Newton-Raphson để tìm căn bậc ba của số lớn
string newton_raphson_cube_root(const string &n) {
    string guess = "1";  // Khởi tạo gần đúng
    string eps = "1e-10"; // Sai số chấp nhận được

    while (true) {
        string guess_cubed = power(guess, 3);
        string next_guess = multiply("3", multiply(guess, power(guess, 2)));
        next_guess = multiply("1", multiply(next_guess, "1"));
        string new_guess = multiply(next_guess, n);
        
        if (abs(stoll(guess_cubed) - stoll(n)) <= stoll(eps)) // Kiểm tra độ chính xác
            return guess;

        guess = new_guess;
    }
}

// In kết quả với 10 chữ số thập phân
int main() {
    string n;
    cin >> n;
    string result = newton_raphson_cube_root(n);
    cout << result << ".0000000000" << endl;
    return 0;
}
