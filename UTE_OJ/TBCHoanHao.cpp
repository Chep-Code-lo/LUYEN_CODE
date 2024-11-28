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
double n, sum_avg, count;
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i){ 
        cin >> x;
        if(check(x)){
            sum_avg += x;
            count++;
        }
    }
    if(sum_avg == 0) cout << 0;
    else{
        double res = sum_avg/count;
        cout << round(res);
    }
}