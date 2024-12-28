// Author : Chép Code Lỏ
// Codeforces : @phamanh24042006
// Github : @Chep-Code-lo

#include <iostream>
#include <vector>
using namespace std;
int n, max_climb, current_climb;
int main(){
    cin >> n;
    vector<int>heights(n);
    for(int i=0; i<n; ++i)  cin >> heights[i];
    for (int i=1; i<n; ++i) {
        if (heights[i] > heights[i - 1]) {
            current_climb += (heights[i] - heights[i - 1]);
            max_climb = max(max_climb, current_climb);
        } else {
            current_climb = 0;
        }
    }
    cout << max_climb;
}