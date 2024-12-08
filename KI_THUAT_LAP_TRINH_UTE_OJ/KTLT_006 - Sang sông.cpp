#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, x, cnt, a[200005];
int main(){
    cin >> n >> x;
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);
    int left = 0, right = n-1;
    while(left <= right){
        if(a[left] + a[right] <= x) left++;
        right--;
        cnt++;
    }
    cout << cnt;
}