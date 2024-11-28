#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string multiplyBigNumbers(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    string result(n + m, '0');

    for (int i = n - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int sum = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = sum % 10 + '0';
            carry = sum / 10;
        }
        result[i] += carry;
    }

    size_t startpos = result.find_first_not_of("0");
    if (startpos != string::npos)
    {
        return result.substr(startpos);
    }
    return "0";
}

string divideBigNumbers(const string &a, int divisor)
{
    string result;
    long long temp = 0;

    for (char digit : a)
    {
        temp = temp * 10 + (digit - '0');
        result += (temp / divisor) + '0';
        temp %= divisor;
    }

    size_t startpos = result.find_first_not_of("0");
    if (startpos != string::npos)
    {
        return result.substr(startpos);
    }
    return "0";
}

int main()
{
    string n;
    cin >> n;

    if (n == "0" || n == "1" || n.size() > 10)
    {
        cout << "0" << endl;
        return 0;
    }

    string S = n;

    string n_plus_1 = to_string(stoll(n) + 1);
    S = multiplyBigNumbers(S, n_plus_1);

    S = divideBigNumbers(S, 2);

    string n_plus_2 = to_string(stoll(n) + 2);
    S = multiplyBigNumbers(S, n_plus_2);

    S = divideBigNumbers(S, 3);

    cout << S << endl;
    return 0;
}
