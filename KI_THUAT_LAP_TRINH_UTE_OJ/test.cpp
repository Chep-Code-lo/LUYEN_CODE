#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<long long> c(n + m - 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            c[i + j] += a[i] * b[j];

    for (size_t i = 0; i < c.size(); ++i) {
        cout << c[i];
        if (i + 1 < c.size()) cout << ' ';
    }
    return 0;
}
