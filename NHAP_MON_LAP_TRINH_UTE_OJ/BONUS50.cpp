#include <iostream>
#include <algorithm>
using namespace std;
int n, k, max_sum, a[50][50];
int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) cin >> a[i][j];
    for(int i=0; i<=n-k; ++i)
        for(int j=0; j<=n-k; ++j) {
            int current_sum = 0;
            for(int x=0; x<k; ++x)
                for(int y=0; y<k; ++y)
                    current_sum += a[i + x][j + y];
            max_sum = max(max_sum, current_sum);
        }
    cout << max_sum;
}
