#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, max_peak, min_valley, a[1000];
int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    max_peak = INT_MIN;
    min_valley = INT_MAX;
    for(int i=0; i<n; ++i) {
        if( a[i] > a[i - 1] || a[i] > a[i + 1])
            max_peak = max(max_peak, a[i]);
        if(a[i] < a[i - 1]|| a[i] < a[i + 1])
            min_valley = min(min_valley, a[i]);
    }
    cout << max_peak << " " << min_valley;
}
