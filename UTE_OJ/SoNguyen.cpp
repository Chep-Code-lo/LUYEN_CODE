#include<iostream>
#include<math.h>
#define int long long
using namespace std;
string s;
int sum, k;
int bin_pow(int x, int y){
	int res = 1;
	while(y > 0){
		if(y & 1)
			res *= x;
		x *= x;
		y >>= 1;
	}
	return res;
}
signed main(){
	cin >> s;
	for(int i=0; i<s.size(); ++i)
		sum += s[i] - '0';
	int n = stoll(s);
	while(bin_pow(2,k) <= n){
		k++;
	}
	k -= 1;
	cout << s.size() << "\n" << sum << "\n" << (k == 0 ? -1 : k ) << "\n";

}