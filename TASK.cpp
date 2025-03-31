#include <bits/stdc++.h>
#include <vector>
//#define int long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
string multiply(string a, string b) {
    vector<int> res(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            res[i + j + 1] += mul;
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }
    string result;
    int i = 0;
    while (i < res.size() && res[i] == 0) i++;
    if (i == res.size()) return "0";
    while (i < res.size()) result += (res[i++] + '0');
    return result;
}

// So sánh hai số lớn dạng chuỗi
bool lessOrEqual(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

// Hàm binary search chính xác
string binarySearch(string num) {
    string l = "0", r = "1" + string(60, '0'), ans = "0";

    while (lessOrEqual(l, r)) {
        string mid;
        string sum = "";
        int carry = 0;
        int i = l.size() - 1, j = r.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int digitL = i >= 0 ? l[i--] - '0' : 0;
            int digitR = j >= 0 ? r[j--] - '0' : 0;
            int temp = digitL + digitR + carry;
            sum = char(temp % 10 + '0') + sum;
            carry = temp / 10;
        }

        // Chia sum cho 2
        mid = "";
        carry = 0;
        for (char c : sum) {
            int cur = carry * 10 + (c - '0');
            mid += (cur / 2 + '0');
            carry = cur % 2;
        }
        if (mid[0] == '0' && mid.size() > 1) mid.erase(0,1);

        string midCubed = multiply(multiply(mid, mid), mid);
        if (lessOrEqual(midCubed, num)) {
            ans = mid;
            l = mid;
            int idx = l.size() - 1;
            while (idx >= 0 && l[idx] == '9') l[idx--] = '0';
            if (idx >= 0) l[idx]++;
            else l = "1" + l;
        } else {
            r = mid;
            int idx = r.size() - 1;
            while (idx >= 0 && r[idx] == '0') r[idx--] = '9';
            if (idx >= 0) r[idx]--;
        }
    }
    return ans;
}

void solve(string s) {
    string num = s + string(30, '0');
    string ans = binarySearch(num);
    while (ans.size() <= 10) ans = "0" + ans;
    cout << ans.substr(0, ans.size() - 10) << "." << ans.substr(ans.size() - 10);
}
int main(){
    file_chuan("TASK");
    string s;
    cin >> s;
    solve(s);
}