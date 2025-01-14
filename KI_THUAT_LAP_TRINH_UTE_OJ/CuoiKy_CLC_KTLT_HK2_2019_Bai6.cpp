//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
const int nmax = 2000;
string S;
int L[nmax + 2][nmax + 2];
int n;
void bpa() {
    string s1 = S;
    reverse(S.begin(), S.end());
    string s2 = S;
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++) {
            if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    cout << L[n][n];
}
int main() {
    cin >> S;
    n = S.size();
    bpa();
    return 0;
}
