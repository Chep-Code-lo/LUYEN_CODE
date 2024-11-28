#include<iostream>
#include<math.h>
using namespace std;
double n, sum_avg, count;
int main(){
    cin >> n;
    for(int x, i=0; i<n; ++i){ 
        cin >> x;
        if(x%5 == 0){
            sum_avg += x;
            count++;
        }
    }
    if(sum_avg == 0) cout << 0;
    else{
        double res = sum_avg/count;
        cout << floor(res);
}
}