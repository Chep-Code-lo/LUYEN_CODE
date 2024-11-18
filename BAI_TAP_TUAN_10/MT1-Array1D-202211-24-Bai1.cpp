#include<iostream>
#include<algorithm>
using namespace std;
int n, a[103], Suffix[103];
int main(){
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i]; 
	for(int i=0; i<n-1; ++i) Suffix[i] = abs(a[i+1] - a[i]);
	cout << *min_element(Suffix, Suffix + n -1);
}