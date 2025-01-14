//Author: Chép-Code-Lỏ
//Github: @Chep-Code-lo
#include<iostream>
using namespace std;
const int N = 1e5;
int n, count;
long a[N+1];
long long s, sum;
int main(){
    cin >> n >> s;
    for(int i=0; i<n; ++i)  cin >> a[i];
    for(int l=0,r=0; r<n; ++r){
        //long long sum=0;
        sum += a[r];
        while(sum > s){
            //count += (n-r);
            sum -= a[l];
            l++;
        }
        count+=(r-l+1);
    }
    cout << count;
}
/*7 20
2 6 4 3 6 8 9*/