#include<iostream>
#include<math.h>
#include<algorithm>
#define int long long
using namespace std;
double x, y;
signed main(){
	cin >> x >> y;
	int a = floor(x);
	int b = floor(y);
	cout << (a*b) / __gcd(a,b) << "\n";
}