#include<iostream>
#include<math.h>
using namespace std;
bool check(int x){
    long long sum=1;
    for(int i=2; i*i<=x; i++)
        if(x%i == 0){
            if(i*i != x) sum += i + x/i;
            else sum += i;
        }
    return(sum == x &&  x!= 1);
}
int n, k, maxx;
int main(){
    cin >> n >> k;
    for(int x, i=0; i<n; ++i) cin >> x, maxx = max(maxx, ((check(x) && x < k) ? x : 0));
    cout << maxx;
}