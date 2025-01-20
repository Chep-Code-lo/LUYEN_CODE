// Author : Chép Code Lỏ
// Codeforces : @phamanh24042006
// Github : @Chep-Code-lo


#pragma GCC optimize("fast-math,O3")
#pragma GCC optimize("no-stack-protector") 
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("tune=native")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <stack>
#include <iomanip>
#define ll long long
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll MAXVAL = 1e6 + 500;

inline string multiply(string a, long long b) {
    string result = "";
    long long carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        long long product = (a[i] - '0') * b + carry;
        result = char(product % 10 + '0') + result;
        carry = product / 10;
    }
    while (carry) {
        result = char(carry % 10 + '0') + result;
        carry /= 10;
    }
    return result;
}

inline string power(string base, int exp) {
    string result = "1";
    for (int i = 0; i < exp; i++) {
        result = multiply(result, stoll(base));
    }
    return result;
}

inline int compare(string a, string b) {
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return 1;
    return a.compare(b);
}

inline string cubeRoot(string n) {
    string low = "0", high = n, ans;

    while (compare(low, high) <= 0) {
        string mid = to_string((stoll(low) + stoll(high)) / 2);
        string midCubed = power(mid, 3);

        if (compare(midCubed, n) <= 0) {
            ans = mid;
            low = to_string(stoll(mid) + 1);
        } else {
            high = to_string(stoll(mid) - 1);
        }
    }
    long double prelow = stold(ans);
    long double prehigh = prelow + 1.0;
    long double preresult = prelow;

    while (prehigh - prelow > 1e-11) {
        long double mid = (prelow + prehigh) / 2.0;
        long double midCubed = mid * mid * mid;

        if (midCubed <= stold(n)) {
            preresult = mid;
            prelow = mid;
        } else {
            prehigh = mid;
        }
    }

    stringstream result, res;
    result << fixed << setprecision(11) << preresult;
    //res << fixed << setprecision(11) << preresult;
    return result.str();
}

int main() { 
    cin.tie(nullptr), cout.tie(nullptr) 
    -> ios_base::sync_with_stdio(false);
    //file_chuan("TASK");
    string n, ans;
    cin >> n;
    ans = cubeRoot(n);
    ans.pop_back();
    cout << ans;

    return 0;   
}