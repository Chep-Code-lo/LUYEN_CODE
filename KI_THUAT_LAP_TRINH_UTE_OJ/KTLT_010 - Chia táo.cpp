#include <iostream>
using namespace std;
#define ll long long
#define INF LLONG_MAX
int n; 
ll a[20], minn = 1e9, sum = 0;
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)  cin >> a[i], sum += a[i];
    // Duyệt qua tất cả các cách chia tập con (2^n trường hợp)
    for (int mask=0; mask<(1 << n); ++mask){
        ll subset_sum = 0;
        for (int i=0; i<n; ++i)
            if(mask & (1 << i)) // Kiểm tra xem quả táo thứ i có trong tập con không
                subset_sum += a[i];
        ll diff = abs(sum - 2*subset_sum); // abs(S1 - S2) = abs(sum - 2*S1)
        minn = min(minn, diff);
    }
    cout << minn;
}
