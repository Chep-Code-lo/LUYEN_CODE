#include<iostream>
#define int long long
using namespace std;
int n, k, l, r=4e9;
signed main(){
	cin >> n;
	while(l<=r){
		int mid = (l+r) / 2;
		int sum = (mid*(mid+1))/2;
		if(sum < n){
			k = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << k << "\n";
}