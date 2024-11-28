#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
double x, y;
int main(){
    cin >> x >> y;
    int xx = floor(x);
    int yy= floor(y);
    cout << __gcd(xx, yy);
}