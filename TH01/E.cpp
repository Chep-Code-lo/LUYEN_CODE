#include <iostream>
#include <string>
using namespace std;

const int nmax = 2000;
string S;
int L[nmax + 2][nmax + 2];
int n;

void bpa() {
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (S[i - 1] == S[j - 1]) {
                L[i][j] = L[i - 1][j + 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j + 1]);
            }
        }
    }
    int res = INT_MIN;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            res = max(res, L[i][j]);
    //cout << n - res;
    int i = n;
    int j = 1;
    string kq = "";
    while (i > 0 && j <= n) {
        if (S[i - 1] == S[j - 1]) {
            kq = kq + S[i - 1];
            i--;
            j++;
        } else {
            if (L[i][j] == L[i - 1][j]) {
                i--;
            } else {
                j++;
            }
        }
    }
    cout << kq.size();
}

int main() {
    cin >> n >> S;
    bpa();
    return 0;
}
