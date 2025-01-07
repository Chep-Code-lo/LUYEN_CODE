#include <iostream>
#include <algorithm>
#define int long long
#define file_chuan(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define file_trau(name) freopen(name".inp","r",stdin); freopen(name".ans","w",stdout); 
using namespace std;
const int N = 1e5+1;
int n, sum_avg, operations, operations_floor, operation_ceil, a[N];
signed main(){
    //file_chuan("TASK")
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i];
    sort(a, a+n);
    int median = a[n/2];
    for(int i=0; i<n; ++i)
        operations += abs(a[i] - median);
    cout << operations;
    /*int sum_avg_floor = sum_avg / n;
    int sum_avg_ceil = (sum_avg + n - 1) / n;
    for(int i=0; i<n; ++i)  operations_floor += abs(a[i] - sum_avg_floor);
    for(int i=0; i<n; ++i)  operation_ceil += abs(a[i] - operation_ceil);
    cout << min(operation_ceil, operations_floor);*/
}