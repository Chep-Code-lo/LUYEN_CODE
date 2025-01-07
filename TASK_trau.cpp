#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout); 
using namespace std;

long long min_operations(vector<long long>& a) {
    long long sum = 0;
    int n = a.size();
    
    for (int num : a) {
        sum += num;
    }
    
    long long avg_floor = sum / n;
    long long avg_ceil = (sum + n - 1) / n;

    long long operations_floor = 0;
    for (int num : a) {
        operations_floor += abs(num - avg_floor);
    }

    long long operations_ceil = 0;
    for (int num : a) {
        operations_ceil += abs(num - avg_ceil);
    }

    return min(operations_floor, operations_ceil);
}

int main() {
    file_trau("TASK")
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << min_operations(a);
    return 0;
}