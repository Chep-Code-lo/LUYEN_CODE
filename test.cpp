#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int64> L(n), R(n), m(n);
        for (int i = 0; i < n; i++) cin >> L[i];
        for (int i = 0; i < n; i++) cin >> R[i];

        // total số găng tay
        int64 total = 0;
        for (int i = 0; i < n; i++) {
            total += L[i] + R[i];
            m[i] = min(L[i], R[i]);
        }

        // sort m giảm dần rồi tính prefix sum
        sort(m.begin(), m.end(), greater<int64>());
        vector<int64> pref(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + m[i-1];
        }

        // minsum = tổng tất cả m[i]
        int64 minsum = pref[n];
        // sum_top = tổng k-1 giá trị m lớn nhất
        int64 sum_top = pref[k-1];

        // Xmax = số găng tay tối đa mà đối thủ có thể rút mà chưa bị bắt buộc có k đôi màu khác nhau
        int64 Xmax = total - minsum + sum_top;
        // đáp án = Xmax + 1
        cout << (Xmax + 1) << "\n";
    }

    return 0;
}
