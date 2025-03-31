#include <bits/stdc++.h>
using namespace std;

string multiply(const string &a, const string &b) {
    vector<int> res(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            int tmp = (a[i] - '0') * (b[j] - '0') + res[i + j + 1];
            res[i + j + 1] = tmp % 10;
            res[i + j] += tmp / 10;
        }
    }
    string result;
    int i = 0;
    while (i < res.size() && res[i] == 0) ++i;
    if (i == res.size()) return "0";
    for (; i < res.size(); ++i) result += char(res[i] + '0');
    return result;
}

bool lessOrEqual(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

string divideByTwo(const string &num) {
    string res;
    int carry = 0;
    for (char digit : num) {
        int current = carry * 10 + (digit - '0');
        res += (current / 2 + '0');
        carry = current % 2;
    }
    int pos = 0;
    while (pos < res.size() - 1 && res[pos] == '0') ++pos;
    return res.substr(pos);
}

string addOne(const string &num) {
    string res = num;
    int i = res.size() - 1;
    while (i >= 0 && res[i] == '9') res[i--] = '0';
    if (i < 0) return "1" + res;
    res[i] += 1;
    return res;
}

string subtractOne(const string &num) {
    string res = num;
    int i = res.size() - 1;
    while (i >= 0 && res[i] == '0') res[i--] = '9';
    if (i >= 0) res[i] -= 1;
    int pos = 0;
    while (pos < res.size() - 1 && res[pos] == '0') ++pos;
    return res.substr(pos);
}

string binarySearch(const string &num) {
    string l = "0", r = num, ans = "0";
    while (lessOrEqual(l, r)) {
        string mid = divideByTwo(multiply(addOne(l), subtractOne(r)));
        string midCubed = multiply(multiply(mid, mid), mid);
        if (lessOrEqual(midCubed, num)) {
            ans = mid;
            l = addOne(mid);
        } else {
            r = subtractOne(mid);
        }
    }
    return ans;
}

void solve(const string &s){
    string num = s + string(30, '0');
    string ans = binarySearch(num);
    ans.insert(ans.begin(), max(0, 11 - (int)ans.size()), '0');
    cout << ans.substr(0, ans.size() - 10) << "." << ans.substr(ans.size() - 10);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    solve(s);
    return 0;
}
