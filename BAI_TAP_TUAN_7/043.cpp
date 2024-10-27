#include<iostream>
using namespace std;
int n, m, a[102][102];
long long sum;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)  cin >> a[i][j];
    for(int j = 0; j < m; j++) {
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[i][j];
        cout << sum << " ";
    }
    return 0;
}

