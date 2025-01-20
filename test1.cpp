#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define file(name) freopen(name".inp","r",stdin); freopen(name".txt1","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout);
#define faster ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e6;
const int N = 5e5;
int n, m, a[N], b[N], dp[N], trace[N], prime[M + 10];

void Eratosthenes_Sieve() {
    for (int i = 1; i <= M; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(M); ++i)
        if (prime[i])
            for (int j = i * i; j <= M; j += i)
                prime[j] = 0;
}

int binary(int l, int r, int x) {
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[b[mid]] <= x) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return b[res];
}

int main() {
    file("TASK");
    faster
    Eratosthenes_Sieve();
    cin >> n;
    for (int x, i = 1; i <= n; ++i) {
        cin >> x;
        if (prime[x]) a[++m] = x;
    }
    dp[1] = 1, b[1] = 1, trace[1] = 0;
    int r = 1;  // Chỉ số của phần tử cuối cùng trong LIS
    for (int i = 2; i <= m; ++i) {
        int k = binary(1, dp[r], a[i]);
        dp[i] = dp[k] + 1;
        trace[i] = k;  // Lưu chỉ số của phần tử trước đó
        b[dp[i]] = i;
        if (dp[i] > dp[r]) r = i;
    }
    cout << dp[r] << "\n"; // In độ dài của LIS

    // Truy vết và in dãy LIS
    vector<int> lis;
    for (int i = r; i > 0; i = trace[i])
        lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());
    for (int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}