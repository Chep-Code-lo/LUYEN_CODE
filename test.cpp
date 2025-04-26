#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                          // number of test cases
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, root;
        cin >> n >> root;           // root is given but not needed

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        /* skip the edges */
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
        }

        /* output the final values of every vertex */
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
