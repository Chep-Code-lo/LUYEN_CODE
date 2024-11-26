#include <iostream>
#include <numeric> 
#include<algorithm> 
using namespace std;
int n , fraction_sum = 0, denominator_lcm = 1;
int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        fraction_sum = fraction_sum * b + a * denominator_lcm;
        denominator_lcm *= b;
    }
    int gcd_value = __gcd(fraction_sum, denominator_lcm);
    fraction_sum /= gcd_value;
    denominator_lcm /= gcd_value;
    cout << fraction_sum << " " << denominator_lcm;
}
