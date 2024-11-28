#include<iostream>
using namespace std;
long long limit, current_sum, max_sum, arry[102];
int main(){
    cin >> limit;
    for(int i=0; i<limit; ++i)  cin >> arry[i];
    max_sum = current_sum =arry[0];
    for(int i=1; i<limit; ++i){
        current_sum = max(arry[i], current_sum + arry[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}
