// Author : Chép Code Lỏ
// Codeforces : @phamanh24042006
// Github : @Chep-Code-lo

#include <iostream>
using namespace std;
int min_bags(int n){
    int max_bags_5 = n / 5;
    for (int bags_5 = max_bags_5; bags_5 >= 0; --bags_5){
        int remaining = n - bags_5 * 5;
        if (remaining % 3 == 0) {
            int bags_3 = remaining / 3;
            return bags_5 + bags_3;
        }
    }
    return -1;
}
int n;
int main(){
    cin >> n;
    cout << min_bags(n);
}
