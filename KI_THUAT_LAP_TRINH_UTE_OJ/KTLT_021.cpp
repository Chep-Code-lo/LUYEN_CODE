//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
using namespace std;
const int N = 1e5;
int n;
long a[N+1];
long long s, sum, count=-1e9;
int main(){
    cin >> n >> s;
    for(int i=0; i<n; ++i)  cin >> a[i];
    for(int l=0,r=0; r<n; ++r){
        //long long sum=0;
        sum += a[r];
        while(sum > s){
            sum -= a[l];
            l++;
        }
        count = max(count, (long long)(r-l+1));
    }
    if(count==-1e9)    cout << -1;
    else    cout << count;
}
/*7 20
2 6 4 3 6 8 9*/