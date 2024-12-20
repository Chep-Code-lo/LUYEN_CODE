#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_median(vector<int>& arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}
int n, k;
int main() {
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i)  cin >> a[i];
    vector<int> medians;
    for(int i=0; i<=n-k; ++i){
        vector<int> add(a.begin() + i, a.begin() + i + k);
        medians.push_back(find_median(add));
    }
    cout << find_median(medians);
}