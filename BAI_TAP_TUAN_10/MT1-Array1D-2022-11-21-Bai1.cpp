#include<iostream>
using namespace std;
int n, maxx, pos_1, pos_2, a[103];
int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    maxx = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > maxx) {
            maxx = a[i];
            pos_1 = pos_2 = i; 
        } else if (a[i] == maxx)
            pos_2 = i; 
    cout << pos_2 - pos_1;
}
